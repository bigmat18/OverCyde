#pragma once
#include "RendererAPI.h"

namespace Core {

    class Renderer {
        public: 
            static void BeginScene();
            static void EndScene();

            static void Submit(const std::shared_ptr<VertexArray>& vertexArray);
    };
}