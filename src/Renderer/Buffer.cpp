#include "Buffer.h"
#include "Renderer.h"
#include "../Log.h"
#include "../OpenGL/OpenGLBuffer.h"

namespace Core {
    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size) {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexBuffer(vertices, size);
        }
        return nullptr;
    }

    IndexBuffer *Create(uint32_t *indices, uint32_t size) {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLIndexBuffer(indices, size);
        }
        return nullptr;
    }
}