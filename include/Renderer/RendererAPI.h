#pragma once
#include "../Core/Pch.h"
#include "../Core/Types.h"
#include "VertexArray.h"

namespace Engine {
    class RendererAPI {
        public:
            enum class API
            {
                None = 0,
                OpenGL = 1
            };

        public:
            virtual void Clear() = 0;
            virtual void SetClearColor(const Vec4f& color) = 0;
            virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;
            virtual void SetViewport(ui32 x, ui32 y, ui32 width, ui32 heigth) = 0;

            static API GetAPI() { return s_API; }
            static RendererAPI* Create();
        private:
            static API s_API;
    };
}
