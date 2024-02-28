#include "OpenGLContext.h"
#include "../Macro.h"

namespace Core {
    OpenGLContext::OpenGLContext(void* windowHandle)
        : m_WindowHandle((GLFWwindow*)windowHandle) {}

    void OpenGLContext::Initialize() {
        glfwMakeContextCurrent(this->m_WindowHandle);
        CORE_ASSERT(glewInit() == GLEW_OK, "Error to init glew");
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(this->m_WindowHandle);
    }
}