#include <Renderer/VertexArray.h>
#include <Renderer/RendererAPI.h>
#include <Renderer/OpenGL/OpenGLVertexArray.h>

namespace Engine {
    VertexArray* VertexArray::Create() {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_ENGINE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexArray();
        }
        return nullptr;
    }
}
