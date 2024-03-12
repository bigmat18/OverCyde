#pragma once
#include "VertexArray.h"

namespace Engine {
    class Renderer {
        public: 
            static void Inizialize();
            static void Shutdown();
        
            static void BeginScene();
            static void EndScene();

            static void Submit(const std::shared_ptr<VertexArray>& vertexArray);
    };
}
