#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "../Renderer/GraphicsContext.h"
#include "../Core/Types.h"

namespace Engine {
    class DefaultWindow : public Window {
        public:
            DefaultWindow(const WindowProps &props);
            virtual ~DefaultWindow();

            void OnUpdate() override; 

            float GetTime() const override { return glfwGetTime(); }
            uint32_t GetWidth() const override { return m_Data.Width; }
            uint32_t GetHeight() const override { return m_Data.Height; }
            const Vec4f GetBGColor() const override { return m_Data.BackgroundColor; }

            void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }

            virtual void *GetNativeWindow() const { return m_Window; }

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
