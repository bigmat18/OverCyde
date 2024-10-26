#include <Renderer/RenderCommand.h>
#include <Renderer/RendererAPI.h>

namespace Engine {
    RendererAPI* RenderCommand::s_RendererAPI = RendererAPI::Create();
}
