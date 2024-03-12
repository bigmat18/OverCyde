#pragma once
#include "Core/Log.h"
#include <Engine.h>

class GameLayer : public Engine::Layer {
    public:
        GameLayer() : m_Time(0.0f), m_Speed(0.2) {};
        
        void OnUpdate(float deltaTime) override;

    private:
        float m_Time;
        float m_Speed;
};
