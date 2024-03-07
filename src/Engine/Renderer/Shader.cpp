#include "Shader.h"
#include "RendererAPI.h"
#include "../OpenGL/OpenGLShader.h"

namespace Core {
    Shader* Shader::Create(const std::string &vertexPath, const std::string &fragmentPath) {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None:     LOG_CORE_ERROR("RendereAPI::None in not supported");
            case RendererAPI::API::OpenGL:   return new OpenGLShader(vertexPath, fragmentPath);
        }

        CORE_ASSERT(false, "API not found");
        return nullptr;
    }
}