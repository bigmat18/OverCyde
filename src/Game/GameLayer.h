#pragma once
#include <Engine.h>

class GameLayer : public Engine::Layer {
    public:
        GameLayer() = default;
        
        void OnUpdate(float deltaTime) override {
            Engine::Renderer2D::DrawTriangle(); 
        }
};
