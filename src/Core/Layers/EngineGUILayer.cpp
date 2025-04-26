#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <Core/Layers/EngineGUILayer.h>
#include <Application.h>

namespace Engine {
    EngineGUILayer::EngineGUILayer() : Layer("EngineGUILayer") {}

    EngineGUILayer::~EngineGUILayer() {}
    
    void EngineGUILayer::OnAttach() {
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

    void EngineGUILayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void EngineGUILayer::OnEvent(Event& event) {
        if (m_BlockEvents) {
            ImGuiIO &io = ImGui::GetIO();
            event.SetHandled(event.IsHandled() || (event.IsInCategory(EventCategoryMouse) && io.WantCaptureMouse));
            event.SetHandled(event.IsHandled() || (event.IsInCategory(EventCategoryKeyboard) && io.WantCaptureKeyboard));
        }
    }

    void EngineGUILayer::OnUpdate(float deltaTime) { 
        this->m_Time = deltaTime; 
    }

    void EngineGUILayer::Begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void EngineGUILayer::End() {
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

    void EngineGUILayer::OnImGuiRender() {
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
    }
}
