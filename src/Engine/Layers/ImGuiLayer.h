#pragma once
#include "Layer.h"

namespace Engine {
    class ENGINE_API ImGuiLayer : public Layer {
        public:
            ImGuiLayer();
            ~ImGuiLayer();
            
            void OnAttach() override;
            void OnDetach() override;
            
            void OnUpdate(float deltaTime) override;
            void OnEvent(Event& event) override;

        private:
            float m_Time;            
    };

}
