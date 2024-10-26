#include <Renderer/Buffer.h>
#include <Renderer/RendererAPI.h>
#include <Core/Log.h>
#include <OpenGL/OpenGLBuffer.h>

namespace Engine {
    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_ENGINE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexBuffer(vertices, size);
        }
        ENGINE_ASSERT(false, "API not found!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t *indices, uint32_t size) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_ENGINE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLIndexBuffer(indices, size);
        }
        ENGINE_ASSERT(false, "API not found!"); 
        return nullptr;
    }
} 
