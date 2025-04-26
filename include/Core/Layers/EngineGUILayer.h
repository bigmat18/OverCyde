#pragma once
#include "Layer.h"

namespace Engine {
    class ENGINE_API EngineGUILayer : public Layer {
        public:
            EngineGUILayer();
            ~EngineGUILayer();
            
            void OnAttach() override;
            void OnDetach() override;

            void OnImGuiRender() override;
            void OnUpdate(float deltaTime) override;
            void OnEvent(Event& event) override;

            void BlockEvents(bool block) { m_BlockEvents = block; }

            void Begin();
            void End();

        private:
            float m_Time;
            bool m_BlockEvents = true;
    };

}
