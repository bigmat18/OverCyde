#include "GraphicsContext.h"
#include "RendererAPI.h"
#include "../OpenGL/OpenGLContext.h"

namespace Engine {
    GraphicsContext* GraphicsContext::Create(void* window) {
        
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLContext(window);
        }

        CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}