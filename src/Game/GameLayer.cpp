#include "GameLayer.h"
#include "Core/Log.h"
#include "Core/Macro.h"
#include "Core/Types.h"
#include "Renderer/Renderer2D.h"
#include "glm/trigonometric.hpp"

void GameLayer::OnUpdate(float deltaTime) {
    this->m_Time += deltaTime * 0.02;
    Engine::Renderer2D::DrawSquare(Engine::Vec3f(-0.75f, 0.0f, 0.0f),
                                   Engine::Vec3f(0.125f, 0.125f, 0.0f),
                                   Engine::Vec4f(1.0f, 0.0f, 0.0f, 1.0f),
                                   Engine::Vec3f(0.0f, 0.0f, glm::sin(this->m_Time) * 360));

    Engine::Renderer2D::DrawCircle(Engine::Vec3f(-0.25f, 0.0f, 0.0f),
                                   0.125f,
                                   Engine::Vec4f(0.0f, 1.0f, 0.0f, 1.0f),
                                   Engine::Vec3f(0.0f, 0.0f, glm::sin(this->m_Time) * 360));
 
    Engine::Renderer2D::DrawTriangle(Engine::Vec3f(0.25f, 0.0f, 0.0f),
                                     Engine::Vec3f(0.125f, 0.125f, 0.0f),
                                     Engine::Vec4f(0.0f, 0.0f, 1.0f, 1.0f),
                                     Engine::Vec3f(0.0f, 0.0f, glm::sin(this->m_Time) * 360));

    Engine::Renderer2D::DrawPolyhedron(8,
                                       Engine::Vec3f(0.75f, 0.0f, 0.0f),
                                       Engine::Vec3f(0.125f, 0.125f, 0.f),
                                       Engine::Vec4f(1.0f, 0.0f, 1.0f, 1.0f),
                                       Engine::Vec3f(0.0f, 0.0f, glm::sin(this->m_Time) * 360));
}

