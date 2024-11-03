#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <Layers/ImGuiLayer.h>
#include <Core/Application.h>
#include <Core/Profiling.h>

namespace Engine {
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

    ImGuiLayer::~ImGuiLayer() {}
    
    void ImGuiLayer::OnAttach() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows

        ImGui::StyleColorsDark();

        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Application &app = Application::Get();
        GLFWwindow *window = static_cast<GLFWwindow *>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnEvent(Event& event) {
        if (m_BlockEvents) {
            ImGuiIO &io = ImGui::GetIO();
            event.SetHandled(event.IsHandled() || (event.IsInCategory(EventCategoryMouse) && io.WantCaptureMouse));
            event.SetHandled(event.IsHandled() || (event.IsInCategory(EventCategoryKeyboard) && io.WantCaptureKeyboard));
        }
    }

    void ImGuiLayer::OnUpdate(float deltaTime) { 
        this->m_Time = deltaTime; 
    }

    void ImGuiLayer::Begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End() {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), 
                                (float)app.GetWindow().GetHeight());

        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void ImGuiLayer::OnImGuiRender() {
        static bool showDemoWindow = false;
        if (showDemoWindow)
            ImGui::ShowDemoWindow(&showDemoWindow);

        int xpos, ypos, width, height;
        auto window = (GLFWwindow *)(Application::Get().GetWindow().GetNativeWindow());
        glfwGetWindowPos(window, &xpos, &ypos);
        glfwGetWindowSize(window, &width, &height);

        ImGui::SetNextWindowPos({static_cast<float>(xpos), static_cast<float>(ypos)});
        ImGui::SetNextWindowSize({static_cast<float>(width) / 10.0f, static_cast<float>(height) / 6.0f});
        ImGui::Begin("FPS");
        ImGui::Text("%d fps", (int)FLOAT_TO_FPS(this->m_Time));
        ImGui::End();

        #ifdef PROFILING
            ImGui::SetNextWindowPos({static_cast<float>(xpos) + (static_cast<float>(width) / 10.0f), static_cast<float>(ypos)});
            ImGui::SetNextWindowSize({(static_cast<float>(width) / 10.0f) * 9.0f, static_cast<float>(height) / 6.0f});
            ImGui::Begin("Profiling");
            ImGui::BeginTable("Times", 5);
            ImGui::TableSetupColumn("Name");
            ImGui::TableSetupColumn("Time");
            ImGui::TableSetupColumn("AVG");
            ImGui::TableSetupColumn("Max");
            ImGui::TableSetupColumn("Min");
            ImGui::TableHeadersRow();

            for(auto &[key, value] : Profiling::GetData()) {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%s", key);
                ImGui::TableNextColumn();
                ImGui::Text("%.6f", value.Time);
                ImGui::TableNextColumn();
                ImGui::Text("%.6f", value.AVGTime);
                ImGui::TableNextColumn();
                ImGui::Text("%.6f", value.MaxTime);
                ImGui::TableNextColumn();
                ImGui::Text("%.6f", value.MinTime);
            }
            ImGui::EndTable();
            ImGui::End();
        #endif
    }
}
