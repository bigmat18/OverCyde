#pragma once
#include "../Renderer/RendererAPI.h"

namespace Engine {
    class OpenGLRendererAPI : public RendererAPI {
        public:
            virtual void Clear() override;

            virtual void SetClearColor(const Vec4f &color) override;

            virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;

            virtual void SetViewport(i32 x, i32 y, i32 width, i32 heigth) override;
    };
}