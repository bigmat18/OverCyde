#include "GameLayer.h"
#include "Core/Types.h"

void GameLayer::OnUpdate(float deltaTime) {
    this->m_Time += deltaTime;

    Engine::Renderer2D::DrawPolyhedron(100,
                                       Engine::Vec3f(-0.5f, -0.30f, 0.0f),
                                       Engine::Vec3f(0.25f, 0.4f, 0.5f));
    Engine::Renderer2D::DrawPolyhedron(100,
                                       Engine::Vec3f(-0.5f, 0.30f, 0.0f),
                                       Engine::Vec3f(0.25f, 0.4f, 0.5f));
    Engine::Renderer2D::DrawPolyhedron(100,
                                       Engine::Vec3f(0.2f, 0.0f, 0.0f),
                                       Engine::Vec3f(0.7f, 0.25f, 0.5f));
}
