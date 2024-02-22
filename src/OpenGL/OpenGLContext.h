#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Renderer/GraphicsContext.h"

namespace Core {
    class OpenGLContext : public GraphicsContext {
        public:
            OpenGLContext(GLFWwindow* windowHandle);

            virtual void Initialize() override;
            virtual void SwapBuffers() override;

        private:
            GLFWwindow* m_WindowHandle;

    };
}