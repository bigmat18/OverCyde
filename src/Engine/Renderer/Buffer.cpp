#include "Buffer.h"
#include "RendererAPI.h"
#include "../Core/Log.h"
#include "../OpenGL/OpenGLBuffer.h"

namespace Engine {
    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexBuffer(vertices, size);
        }
        return nullptr;
    }

    IndexBuffer *Create(uint32_t *indices, uint32_t size) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLIndexBuffer(indices, size);
        }
        return nullptr;
    }
}