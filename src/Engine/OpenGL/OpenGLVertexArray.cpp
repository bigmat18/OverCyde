#include <GL/glew.h>
#include "OpenGLVertexArray.h"

namespace Engine {
    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &this->m_ID);
    }

    void OpenGLVertexArray::Bind() const {
        glBindVertexArray(this->m_ID);
    }

    void OpenGLVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) {
        this->Bind();
        vertexBuffer->Bind();
        uint32_t index = 0;
        const auto& layout = vertexBuffer->GetLayout();
        for(const auto& element : layout) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, 
                                  element.GetComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.Type),
                                  element.Normalized,
                                  layout.GetStride(),
                                  (const void*)element.Offset);
            index++;
        }
        this->m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) {
        this->Bind();
        indexBuffer->Bind();
        this->m_IndexBuffers = indexBuffer;
    }
}
