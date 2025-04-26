#pragma once
#include <GLFW/glfw3.h>

#include "../VertexArray.h"

#define GL_BOOL 0x8B56

namespace Engine {
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
            default:                       ENGINE_ASSERT(false, "Unknown type None");
        }

        ENGINE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    class OpenGLVertexArray : public VertexArray {
        public:
            OpenGLVertexArray();
            virtual ~OpenGLVertexArray() = default;

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
            virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;

            virtual const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const override {
                return this->m_VertexBuffer;
            };
            virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override {
                return this->m_IndexBuffer;
            };

        private:
            std::shared_ptr<VertexBuffer> m_VertexBuffer;
            std::shared_ptr<IndexBuffer> m_IndexBuffer;
            uint32_t m_ID;
    
    };

}
