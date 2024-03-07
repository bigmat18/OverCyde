#pragma once
#include "../Renderer/RendererAPI.h"

namespace Core {
    class OpenGLRendererAPI : public RendererAPI {
        public:
            virtual void Clear() override;
            virtual void SetClearColor(const Vec4f &color) override;

            virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;
    };
}