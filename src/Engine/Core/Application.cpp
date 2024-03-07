#include "Application.h"
#include "Log.h"
#include "../Renderer/RenderCommand.h"
#include "../Layers/ExampleLayer.h"
#include "../Events/KeyCode.h"

#define BIND_FUN(x) std::bind(&x, this, std::placeholders::_1)
#define BLACK_COLOR 0x0000FFFF

namespace Core {
    Application *Application::s_Instance = nullptr;

    Application *Application::GetInstance() {
        if (s_Instance == nullptr)
            s_Instance = new Application();
        return s_Instance;
    };


    Application::Application() {
        this->m_Window = std::unique_ptr<Window>(Window::Create());
        this->m_Window->SetEventCallback(BIND_FUN(Application::OnEvent));
        this->PushLayer(new ExampleLayer());
    }

    Application::~Application() {}

    void Application::Run() {
        while(this->m_Running){
            this->ProcessEvents();
            this->Update();
            this->GenerateOutput();

            this->m_Window->OnUpdate();
        }
    }

    void Application::ProcessEvents() {
        for (auto e : this->m_EventStack)
        {
            LOG_CORE_INFO("Event {0}", e->ToString());
            for (auto l : this->m_LayerStack)
            {
                if (!e->IsHandled())
                    l->OnEvent(*e);
            }
            delete e;
        }
        this->m_EventStack.clear();
    }

    void Application::Update() {
        //
    }

    void Application::GenerateOutput() {
        RenderCommand::SetClearColor({HEX_COLOR(BLACK_COLOR)});
        RenderCommand::Clear();
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
        dispatcher.Dispatch<WindowResizeEvent>(BIND_FUN(Application::OnWindowResize));
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

    bool Application::OnWindowResize(WindowResizeEvent& e){
        return true;
    }

}