#include "Application.h"  
#include "Log.h"
#include "../Events/KeyCode.h"
#include "../Renderer/RenderCommand.h"
#include "Macro.h"

#define BIND_FUN(x) std::bind(&x, this, std::placeholders::_1)

namespace Engine {
    Application *Application::s_Instance = nullptr;

    Application *Application::SetInstance(Application *instance) {
        if (s_Instance == nullptr)
            s_Instance = instance;
        else
            delete instance;

        return Application::s_Instance;
    }

    Application::Application(const WindowProps& props) {
        this->m_Window = std::unique_ptr<Window>(Window::Create(props));
        this->m_Window->SetEventCallback(BIND_FUN(Application::OnEvent));
    }

    void Application::Run() {
        while(this->m_Running){
            this->ProcessEvents();
            this->Update();
            this->GenerateOutput();
            this->m_Window->OnUpdate();
        }
    }
    

    void Application::ProcessEvents() {
        for (auto e : this->m_EventStack){
            LOG_ENGINE_INFO("Event {0}", e->ToString());
            for (auto l : this->m_LayerStack){
                if (!e->IsHandled())
                    l->OnEvent(*e);
            }
            delete e;
        }
        this->m_EventStack.clear();
    }

    void Application::Update() {}
    
    void Application::GenerateOutput() {
        RenderCommand::SetClearColor(this->m_Window->GetBGColor());
        RenderCommand::Clear();

        for (auto l : this->m_LayerStack) {
            l->OnUpdate();
        }
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
        return true;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        this->m_Running = false;
        return true;
    }

}
