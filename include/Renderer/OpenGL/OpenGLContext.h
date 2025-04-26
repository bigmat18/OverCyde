#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../GraphicsContext.h"

namespace Engine {
    class OpenGLContext : public GraphicsContext {
        public:
            OpenGLContext(void* windowHandle);

            virtual void Initialize() override;
            virtual void SwapBuffers() override;

        private:
            GLFWwindow* m_WindowHandle;

    };
}