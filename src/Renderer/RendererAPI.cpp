#include "RendererAPI.h"
#include "../OpenGL/OpenGLRendererAPI.h"
#include "../Macro.h"

namespace Core {
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	RendererAPI* RendererAPI::Create() {
		switch (s_API)
		{
			case RendererAPI::API::None:    CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return new OpenGLRendererAPI();
		}

		CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}