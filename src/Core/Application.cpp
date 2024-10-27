#include <Core/Application.h> 
#include <Events/KeyCode.h>
#include <Renderer/RenderCommand.h>
#include <Renderer/Renderer.h>
#include <Layers/ImGuiLayer.h>
#include <Core/Log.h>
#include <Core/Macro.h>
#include <Core/Profiling.h>

namespace Engine {
    Application *Application::s_Instance = nullptr;

    Application *Application::SetInstance(Application *instance) {
        if (s_Instance == nullptr)
            s_Instance = instance;
        else
            delete instance;

        return Application::s_Instance; 
    }

    Application::Application(const ApplicationProps& props) : m_Props(props) {
        this->SetInstance(this);
        this->m_Window = std::unique_ptr<Window>(Window::Create(this->m_Props.WProps));
        this->m_Window->SetEventCallback(BIND_FUN(Application::OnEvent));
        Renderer::Inizialize(this->m_Props.RType);

        this->m_ImGuiLayer = new ImGuiLayer();
        this->m_LayerStack.PushOverlay(m_ImGuiLayer);
    }

    void Application::Run() {

        while(this->m_Running){ 
            {  
                PROFILE_SCOPE("Application::Run()");
        
                float deltaTime = this->CalculateDeltaTime();
                
                RenderCommand::SetClearColor(glm::normalize(this->m_Props.BGColor));
                RenderCommand::Clear();

                {
                    PROFILE_SCOPE("Application::Run::Update()");
                    for (Layer* layer : m_LayerStack) {
                        layer->OnUpdate(deltaTime);
                    }
                    
                    m_ImGuiLayer->Begin();
                    for (Layer* layer : m_LayerStack) {
                        layer->OnImGuiRender();
                    }
                    m_ImGuiLayer->End();

                    this->m_Window->OnUpdate();
                }
            }
        }
    }

    float Application::CalculateDeltaTime() {
        float currentTime, deltaTime;

        do {
            currentTime = this->m_Window->GetTime();
            deltaTime = currentTime - this->m_LastFrameTime;
        } while (deltaTime < FPS_TO_FLOAT(120.0f));

        this->m_LastFrameTime = currentTime;

        return deltaTime; 
    }
    
    void Application::PushLayer(Layer *layer) {
        this->m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer) {
        this->m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e){
        PROFILE_SCOPE("Application::OnEvent()");

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_FUN(Application::OnWindowClose));
        dispatcher.Dispatch<KeyPressedEvent>(BIND_FUN(Application::OnKeyPressed));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_FUN(Application::OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
            if (!e.IsHandled()) 
                (*it)->OnEvent(e);
        }
    }

    bool Application::OnKeyPressed(KeyPressedEvent& e){
        switch (e.GetKeyCode()) {
            case Key::Escape: this->m_Running = false;
        }
        return false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        this->m_Running = false;
        return false;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e){
        RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeigth());
        return false;
    }

}
