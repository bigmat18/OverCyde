#pragma once
#include "Layer.h"

namespace Core {
    class ExampleLayer : public Layer {
        public:
            ExampleLayer();

            void OnAttach() override;
            void OnDetach() override;
            void OnUpdate() override;
            void OnEvent(Event& event) override;
    };
}