#include <GLFW/glfw3.h>
#include <OpenGL/OpenGLRendererAPI.h>

namespace Engine {
    void OpenGLRendererAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::SetClearColor(const Vec4f &color) {
        glClearColor(color.x, color.y, color.z, color.w);
    }

    void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) {
        vertexArray->Bind();
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRendererAPI::SetViewport(ui32 x, ui32 y, ui32 width, ui32 heigth) {
        glViewport(x, y, width, heigth);
    }
}
