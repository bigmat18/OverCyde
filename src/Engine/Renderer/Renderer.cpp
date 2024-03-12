#include "Renderer.h"
#include "RenderCommand.h"
#include "Renderer2D.h"

namespace Engine {

    void Renderer::Inizialize() {
        Renderer2D::Inizialize();
    }


    void Renderer::Shutdown() {
        Renderer2D::Inizialize();
    }


    void Renderer::BeginScene() {

    }

    void Renderer::EndScene() {

    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
        RenderCommand::DrawIndex(vertexArray);
    }
}
