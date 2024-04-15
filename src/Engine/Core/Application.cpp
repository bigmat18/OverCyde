#include "Application.h"  
#include "../Events/KeyCode.h"
#include "../Renderer/RenderCommand.h"
#include "../Renderer/Renderer.h"
#include "../Layers/ImGuiLayer.h"
#include "Log.h"
#include "Macro.h"
#include "Profiling.h"

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
                this->ProcessEvents();
        
                float deltaTime = this->CalculateDeltaTime();
                
                RenderCommand::SetClearColor(glm::normalize(this->m_Props.BGColor));
                RenderCommand::Clear();

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

    void Application::ProcessEvents() {
        for (auto event : this->m_EventStack){
            for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it){
                if (!event->IsHandled())
                    (*it)->OnEvent(*event);
            }
            delete event;
        }
        this->m_EventStack.clear();
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
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_FUN(Application::OnWindowClose));
        dispatcher.Dispatch<KeyPressedEvent>(BIND_FUN(Application::OnKeyPressed));
        this->m_EventStack.push_back(&e);
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

}
