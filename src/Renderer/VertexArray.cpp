#include "VertexArray.h"
#include "../Pch.h"
#include "../OpenGL/OpenGLVertexArray.h"
#include "Renderer.h"

namespace Core {
    VertexArray* VertexArray::Create() {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexArray();
        }
        return nullptr;
    }
}