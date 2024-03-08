#include "RenderCommand.h"
#include "RendererAPI.h"
#include "../OpenGL/OpenGLRendererAPI.h"

namespace Engine {
    RendererAPI* RenderCommand::s_RendererAPI = RendererAPI::Create();
}