#pragma once
#include "../RendererAPI.h"

namespace Engine {
    class OpenGLRendererAPI : public RendererAPI {
        public:
            virtual void Clear() override;

            virtual void SetClearColor(const Vec4f &color) override;

            virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;

            virtual void SetViewport(ui32 x, ui32 y, ui32 width, ui32 heigth) override;
    };
}