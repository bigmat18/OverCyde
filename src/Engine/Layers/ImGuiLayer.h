#pragma once
#include "Layer.h"

namespace Engine {
    class ImGuiLayer : public Layer {
        public:
            ImGuiLayer();
            ~ImGuiLayer();
            
            void OnUpdate(float deltaTime) override;
            void OnEvent(Event& event) override;

        private:
            
    };

}
