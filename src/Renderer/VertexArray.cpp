#include "VertexArray.h"
#include "../Pch.h"
#include "../OpenGL/OpenGLVertexArray.h"
#include "Renderer.h"

namespace Core {
    VertexArray* VertexArray::Create() {
        switch (Renderer::GetAPI()) {
            case RendererAPI::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::OpenGL:   return new OpenGLVertexArray();
        }
        return nullptr;
    }
}