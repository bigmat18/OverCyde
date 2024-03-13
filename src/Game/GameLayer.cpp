#include "GameLayer.h"
#include "Core/Log.h"
#include "Core/Macro.h"
#include "Core/Types.h"
#include "Renderer/Renderer2D.h"
#include "glm/trigonometric.hpp"

void GameLayer::OnUpdate(float deltaTime) {
    this->m_Time += deltaTime * 0.02;
    
    Engine::Renderer::Draw2DSquare(Engine::Vec2f(-0.75f, 0.0f),
                                   Engine::Vec2f(0.125f, 0.125f),
                                   Engine::Vec4f(1.0f, 0.0f, 0.0f, 1.0f),
                                   glm::sin(this->m_Time) * 360);

    Engine::Renderer::Draw2DCircle(0.125f,
                                   Engine::Vec2f(-0.25f, 0.0f),
                                   Engine::Vec4f(0.0f, 1.0f, 0.0f, 1.0f),
                                   glm::sin(this->m_Time) * 360);
 
    Engine::Renderer::Draw2DTriangle(Engine::Vec2f(0.25f, 0.0f),
                                     Engine::Vec2f(0.125f, 0.125f),
                                     Engine::Vec4f(0.0f, 0.0f, 1.0f, 1.0f),
                                     glm::sin(this->m_Time) * 360);

    Engine::Renderer::Draw2DPolyhedron(8,
                                       Engine::Vec2f(0.75f, 0.0f),
                                       Engine::Vec2f(0.125f, 0.125f),
                                       Engine::Vec4f(1.0f, 0.0f, 1.0f, 1.0f),
                                       glm::sin(this->m_Time) * 360);
}

