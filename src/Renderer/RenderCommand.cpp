#include "RenderCommand.h"
#include "../OpenGL/OpenGLRendererAPI.h"
#include "RendererAPI.h"

namespace Core {
    RendererAPI* RenderCommand::s_RendererAPI = RendererAPI::Create();
}