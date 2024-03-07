#pragma once
#include "../Renderer/VertexArray.h"
#include <GLFW/glfw3.h>

namespace Core {
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:    return GL_FLOAT;
            case ShaderDataType::Float2:   return GL_FLOAT;
            case ShaderDataType::Float3:   return GL_FLOAT;
            case ShaderDataType::Float4:   return GL_FLOAT;
            case ShaderDataType::Mat3:     return GL_FLOAT;
            case ShaderDataType::Mat4:     return GL_FLOAT;
            case ShaderDataType::Int:      return GL_INT;
            case ShaderDataType::Int2:     return GL_INT;
            case ShaderDataType::Int3:     return GL_INT;
            case ShaderDataType::Int4:     return GL_INT;
            case ShaderDataType::Bool:     return GL_BOOL;
        }

        CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    class OpenGLVertexArray : public VertexArray {
        public:
            OpenGLVertexArray();
            virtual ~OpenGLVertexArray() = default;

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
            virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const {
                return this->m_VertexBuffers;
            };
            virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const {
                return this->m_IndexBuffers;
            };

        private:
            std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
            std::shared_ptr<IndexBuffer> m_IndexBuffers;
            uint32_t m_ID;
    
    };

}