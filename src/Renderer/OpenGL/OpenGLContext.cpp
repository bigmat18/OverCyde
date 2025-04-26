#include <Renderer/OpenGL/OpenGLContext.h>
#include <Core/Utils.h>

namespace Engine {
    OpenGLContext::OpenGLContext(void* windowHandle)
        : m_WindowHandle((GLFWwindow*)windowHandle) {}

    void OpenGLContext::Initialize() {
        glfwMakeContextCurrent(this->m_WindowHandle);
        ENGINE_ASSERT(glewInit() == GLEW_OK, "Error to init glew");
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(this->m_WindowHandle);
    }
}
