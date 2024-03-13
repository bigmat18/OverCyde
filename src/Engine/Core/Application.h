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

            /**
             * Adding layer at the end of layer stack
             * @param layer the layer to add
             */
            void PushLayer(Layer *layer);

            /**
             * Adding layer at the top of layer stack
             * @param layer the layer to add
             */
            void PushOverlay(Layer *layer);

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
            void OnEvent(Event& e);
            float CalculateDeltaTime();        

            bool m_Running = true;
            bool m_Minimized = false;
            float m_LastFrameTime = 0.0f;
            std::unique_ptr<Window> m_Window;
            std::vector<Event*> m_EventStack;
            LayerStack m_LayerStack;

    };
}
