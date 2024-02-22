#include "OpenGLContext.h"
#include "../Utils.h"

namespace Core {
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
        : m_WindowHandle(windowHandle) {}

    void OpenGLContext::Initialize() {
        glfwMakeContextCurrent(this->m_WindowHandle);
        CORE_ASSERT(glewInit() == GLEW_OK, "Error to init glew");
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(this->m_WindowHandle);
    }
}