#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "../Core/Pch.h"
#include "../Renderer/GraphicsContext.h"

namespace Core {

    class DefaultWindow : public Window {
        public:
            DefaultWindow(const WindowProps &props);
            virtual ~DefaultWindow();

            void OnUpdate() override;

            uint32_t GetWidth() const override { return m_Data.Width; }
            uint32_t GetHeight() const override { return m_Data.Height; }

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
                bool VSync;

                EventCallbackFn EventCallback;
            };

            WindowData m_Data;
    };
}