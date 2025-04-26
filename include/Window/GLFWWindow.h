#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "../Renderer/GraphicsContext.h"
#include "../Core/Types.h"

namespace Engine {
    class GLFWWindow : public Window {
        public:
            GLFWWindow(const WindowProps &props);
            virtual ~GLFWWindow();

            void OnUpdate() override; 

            float GetTime() const override { return glfwGetTime(); }
            uint32_t GetWidth() const override { return m_Data.Width; }
            uint32_t GetHeight() const override { return m_Data.Height; }
            const Vec4f GetBGColor() const override { return m_Data.BackgroundColor; }
            virtual void *GetNativeWindow() const override { return m_Window; }

            void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }


            static Window *Create(const WindowProps &props = WindowProps());

        private:
            virtual void Initialize(const WindowProps &props);
            virtual void Shutdown();

        private:
            GLFWwindow *m_Window;
            GraphicsContext *m_Context;

            struct WindowData {
                std::string Title;
                unsigned int Width, Height;
                Vec4f BackgroundColor;
                
                EventCallbackFn EventCallback;
            };

            WindowData m_Data;
    };
}
