#pragma once
#include <Window/Window.h>
#include <Core/Events/Event.h>
#include <Core/Events/ApplicationEvent.h>
#include <Core/Events/KeyEvent.h>

#include <Core/Layers/LayerStack.h>
#include <Core/Layers/Layer.h>
#include <Core/Layers/EngineGUILayer.h>

#include <Core/Utils.h>
#include <memory>

#define BACKGROUND_COLOR 0x000000FF

namespace Engine {

    /**
     * The props of application to customize the rendering type,
     * background color and window props (Height, Width, Title)
    */
    struct ApplicationProps {
        /**
         * The Window props (default is the default value of WindowProps)
        */
        WindowProps WProps;
        /**
         * Background color rappresented in Vec4f(r, g, b, a) with value between 0, 1 (normalized). If you want use
         * the HEX_COLOR converter you must create a Vec4f and normalized it with glm::normalize.
         * (default = white color)
        */
        Vec4f       BGColor;

        /**
         * Renderer types (Renderer2D, Renderer3D) to select the renderer's geomentry
         * to inizialize (use Renderer::RendererType enum)
         * (default = 0 that is no renderer inzialize)
        */
        ui32        RType;

        bool        ActiveCamera;

        bool        ActiveDebugging;
        
        /** The costructorn for ApplicationProps with default value: WProps = WindowProps default, BGColor = White color, RType = 0*/
        ApplicationProps(const WindowProps &windowProps = WindowProps(),
                         const Vec4f &backgroundColor = Vec4f(HEX_COLOR(BACKGROUND_COLOR)),
                         ui32 rendererType = 0,
                         bool activeCamera = false,
                         bool activeDebugging = false) : 
        WProps(windowProps), 
        BGColor(backgroundColor), 
        RType(rendererType),
        ActiveCamera(activeCamera),
        ActiveDebugging(activeDebugging) {}
    };
     
    class ENGINE_API Application {
        public:
            Application(Application &value) = delete;
            void operator=(const Application &) = delete;
            virtual ~Application() = default;

            static Application& Get() { return *s_Instance; }

            /**
             * Method to overwrite to create the application and return it.
             * Inside this method you can setup ApplicationProps or any pre start config, 
             * after that call SetInstance protected method to setup Application
            */
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

            Window& GetWindow() const { return *this->m_Window; }

        protected:
            /**
             * Default constructor callable only in sub classes
             * @param props the props of application (default = default ApplicationProps config)
            */
            Application(const ApplicationProps& props = ApplicationProps());

            /** 
             * It set up the application with the instance and return it. This is a Singleton class, if you have alredy
             * call this method the s_Instance application isn't overwrite but return the older instance
             * @param instance a pointer to the instance to set up
             * @return return the instance set up 
            */
            static Application *SetInstance(Application *instance);

        private:
            bool OnWindowClose(WindowCloseEvent &e);
            bool OnWindowResize(WindowResizeEvent &e);
            bool OnKeyPressed(KeyPressedEvent &e);

            static Application* s_Instance;

            void OnEvent(Event& e);
            float CalculateDeltaTime();

            bool m_Running = true;
            bool m_Minimized = false;
            float m_LastFrameTime = 0.0f;
            std::unique_ptr<Window> m_Window;

            EngineGUILayer* m_GUILayer;
            LayerStack m_LayerStack;
            ApplicationProps m_Props;
    };
}
