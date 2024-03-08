#include "Renderer.h"
#include "RenderCommand.h"

namespace Engine {

    void Renderer::BeginScene() {

    }

    void Renderer::EndScene() {

    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
        RenderCommand::DrawIndex(vertexArray);
    }
}