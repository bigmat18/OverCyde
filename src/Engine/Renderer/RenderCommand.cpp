#include "RenderCommand.h"
#include "RendererAPI.h"
#include "../OpenGL/OpenGLRendererAPI.h"

namespace Core {
    RendererAPI* RenderCommand::s_RendererAPI = RendererAPI::Create();
}