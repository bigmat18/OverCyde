#include "GameLayer.h"

void GameLayer::OnUpdate(float deltaTime) {
    this->m_Rotation = (this->m_Rotation + (int)(360 * deltaTime * 0.7)) % 360;

    Engine::Renderer::BeginScene(deltaTime);

    Engine::Renderer::Draw2DTexture("assets/sprites/matt.png", 
                                    Engine::Vec2f(0.0f, 0.0f),
                                    Engine::Vec2f(0.25f, 0.25f),
                                    this->m_Rotation);

    // Engine::Renderer::Draw2DSquare(Engine::Vec2f(-0.75f, 0.0f),
    //                                Engine::Vec2f(0.125f, 0.125f),
    //                                Engine::Vec4f(1.0f, 0.0f, 0.0f, 1.0f),
    //                                this->m_Rotation);

    // Engine::Renderer::Draw2DCircle(0.125f,
    //                                Engine::Vec2f(-0.25f, 0.0f),
    //                                Engine::Vec4f(0.0f, 1.0f, 0.0f, 1.0f),
    //                                this->m_Rotation);

    // Engine::Renderer::Draw2DTriangle(Engine::Vec2f(0.25f, 0.0f),
    //                                  Engine::Vec2f(0.125f, 0.125f),
    //                                  Engine::Vec4f(0.0f, 0.0f, 1.0f, 1.0f),
    //                                  this->m_Rotation);

    // Engine::Renderer::Draw2DPolyhedron(8,
    //                                    Engine::Vec2f(0.75f, 0.0f),
    //                                    Engine::Vec2f(0.125f, 0.125f),
    //                                    Engine::Vec4f(1.0f, 0.0f, 1.0f, 1.0f),
    //                                    this->m_Rotation);

    Engine::Renderer::EndScene();
}