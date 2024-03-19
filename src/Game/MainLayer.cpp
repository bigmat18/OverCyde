#include "MainLayer.h"

using namespace Engine;

void MainLayer::OnEvent(Event& event) {
    EventDispatcher dispatcher = EventDispatcher(event);
    dispatcher.Dispatch<KeyPressedEvent>(BIND_FUN(MainLayer::OnKeyPressed));
}

void MainLayer::OnUpdate(float deltaTime) {
    for (int i = 0; i < this->counter; i++) {
        Renderer::Draw2DTriangle(
            Vec2f(0.0f + (i * 0.05f), 0.0f + (i * 0.05f)),
            Vec2f(0.125f + (i * 0.05f), 0.125f + (i * 0.05f)),
            Vec4f(0.0f + (i * 0.1f), 0.0f + (i * 0.1f), 1.0f + (i * 0.05f), 1.0f+ (i * 0.05f)),
            45.0f + (i * 0.05f)
        );
    }
}

bool MainLayer::OnKeyPressed(KeyPressedEvent& kpe) {
    LOG_CLIENT_INFO(kpe.GetKeyCode());

    this->counter++;

    return true;
}