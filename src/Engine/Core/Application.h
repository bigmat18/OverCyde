#pragma once
#include "../Window/Window.h"
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/KeyEvent.h"
#include "../Layers/LayerStack.h"
#include "../Layers/Layer.h"
#include "Macro.h"

namespace Engine {    
     
    class ENGINE_API Application {
        public:
            Application(Application &value) = delete;
            void operator=(const Application &) = delete;
            virtual ~Application() = default;

            static Application *Create();

            void OnEvent(Event& e);
            void PushLayer(class Layer *layer);
            void PushOverlay(class Layer *layer);

            void Run();

        protected:
            Application(const WindowProps& props = WindowProps());
            static Application *SetInstance(Application *instance);

        private:
            bool OnWindowClose(WindowCloseEvent &e);
            bool OnWindowResize(WindowResizeEvent &e);
            bool OnKeyPressed(KeyPressedEvent &e);

            static Application* s_Instance;

            void ProcessEvents();
            void Update();
            void GenerateOutput();

            bool m_Running = true;
            bool m_Minimized = false;
            float m_LastFrameTime = 0.0f;
            std::unique_ptr<Window> m_Window;
            std::vector<Event*> m_EventStack;
            LayerStack m_LayerStack;

    };
}
