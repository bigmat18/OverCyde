#include <GL/glew.h>
#include <Renderer/OpenGL/OpenGLVertexArray.h>

namespace Engine {
    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &this->m_ID);
    }

    void OpenGLVertexArray::Bind() const {
        glBindVertexArray(this->m_ID);
        this->m_VertexBuffer->Bind();
        this->m_IndexBuffer->Bind();
    }

    void OpenGLVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) {
        glBindVertexArray(this->m_ID);
        vertexBuffer->Bind();
        uint32_t index = 0;
        const auto& layout = vertexBuffer->GetLayout();
        for(const auto& element : layout) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, 
                                  element.GetComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.Type),
                                  element.Normalized ? GL_TRUE : GL_FALSE,
                                  layout.GetStride(),
                                  (const void*)element.Offset);
            index++;
        }
        this->m_VertexBuffer = vertexBuffer;
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) {
        glBindVertexArray(this->m_ID);
        indexBuffer->Bind();
        this->m_IndexBuffer = indexBuffer;
    }
}
