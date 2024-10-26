#include <Engine.h>

class GameLayer : public Engine::Layer {
    public:
        GameLayer() : Layer("GameLayer"), m_Rotation(0) {}

        void OnUpdate(float deltaTime) override;
        
    private:
        int m_Rotation;
};