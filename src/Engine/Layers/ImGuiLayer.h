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

            void BlockEvents(bool block) { m_BlockEvents = block; }

        private:
            float m_Time;
            bool m_BlockEvents = true;
    };

}
