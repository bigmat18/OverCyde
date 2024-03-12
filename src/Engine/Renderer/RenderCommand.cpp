#include "RenderCommand.h"
#include "RendererAPI.h"

namespace Engine {
    RendererAPI* RenderCommand::s_RendererAPI = RendererAPI::Create();
}
