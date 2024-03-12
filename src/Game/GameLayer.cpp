#include "GameLayer.h"
#include "Core/Types.h"
#include "glm/trigonometric.hpp"

void GameLayer::OnUpdate(float deltaTime) {
    this->m_Time += deltaTime * 0.002;
    Engine::Renderer2D::DrawTriangle(Engine::Vec3f(0.0f, 0.0f, 0.0f),
                                     Engine::Vec3f(0.5, 0.5, 0.5),
                                     Engine::Vec4f(1.0f, 1.0f, 1.0f, 1.0f),
                                     Engine::Vec3f(glm::sin(m_Time) * 360, glm::cos(m_Time) * 360, 0.0f)); 
}
