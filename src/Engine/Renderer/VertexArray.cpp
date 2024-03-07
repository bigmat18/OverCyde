#include "VertexArray.h"
#include "RendererAPI.h"
#include "../Core/Pch.h"
#include "../OpenGL/OpenGLVertexArray.h"

namespace Core {
    VertexArray* VertexArray::Create() {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLVertexArray();
        }
        return nullptr;
    }
}