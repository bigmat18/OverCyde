#pragma once
#include "../Renderer/Buffer.h"

namespace Core {    
    class OpenGLVertexBuffer : public VertexBuffer {
        public:
            OpenGLVertexBuffer(float *vertices, uint32_t size);
            virtual ~OpenGLVertexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual const void SetLayout(const VertexBufferLayout &layout) override {
                this->m_Layout = layout;
            };
            
            virtual const VertexBufferLayout &GetLayout() const override {
                return this->m_Layout;
            };

        private:
            uint32_t m_ID; // VBO
            VertexBufferLayout m_Layout;
    };

    class OpenGLIndexBuffer : public IndexBuffer{
        public:
            OpenGLIndexBuffer(uint32_t *indeces, uint32_t count);
            virtual ~OpenGLIndexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual uint32_t GetCount() const { return this->m_Count; }

        private:
            uint32_t m_ID; // EBO
            uint32_t m_Count;
    };
}