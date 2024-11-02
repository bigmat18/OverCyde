#pragma once
#include "RendererAPI.h"

namespace Engine {
    class RenderCommand {
        public:
            inline static void SetClearColor(const Vec4f color) {
                s_RendererAPI->SetClearColor(color);
            }

            inline static void Clear() {
                s_RendererAPI->Clear();
            }

            inline static void DrawIndex(const std::shared_ptr<VertexArray>& vertexArray) {
                s_RendererAPI->DrawIndexed(vertexArray);
            }

            inline static void SetViewport(ui32 x, ui32 y, ui32 width, ui32 heigth) {
                s_RendererAPI->SetViewport(x, y, width, heigth);
            }

        private:
            static RendererAPI* s_RendererAPI;
    };
}