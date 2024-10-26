#pragma once
#include "../Core/Input.h"

namespace Engine {
    class DefaultWindowInput : public Input {
        protected:
            virtual bool IsKeyPressedImpl(KeyCode code) override;

            virtual bool IsMouseButtonPressedImpl(MouseCode button) override;

            virtual glm::vec2 GetMousePositionImpl() override;

            virtual float GetMouseXImpl() override;

            virtual float GetMouseYImpl() override;
    };
}