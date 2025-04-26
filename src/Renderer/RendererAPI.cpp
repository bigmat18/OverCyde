#include <Renderer/RendererAPI.h>
#include <Renderer/OpenGL/OpenGLRendererAPI.h>

#include <Core/Utils.h>

namespace Engine {
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	RendererAPI* RendererAPI::Create() {
		switch (s_API)
		{
			case RendererAPI::API::None:    LOG_ENGINE_ERROR("RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL:  return new OpenGLRendererAPI();
		}

		ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
