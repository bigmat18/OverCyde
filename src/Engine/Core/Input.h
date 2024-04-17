#pragma once
#include "../Events/KeyCode.h"
#include "../Events/MouseCode.h"
#include <glm/glm.hpp>

namespace Engine {
    class Input {
        public:
            inline static bool IsKeyPressed(KeyCode code) { return s_Instance->IsKeyPressedImpl(code); }

            inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
            
            inline static glm::vec2 GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

            inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }

            inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

        protected:
            virtual bool IsKeyPressedImpl(KeyCode code) = 0;

            virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;

            virtual glm::vec2 GetMousePositionImpl() = 0;

            virtual float GetMouseXImpl() = 0;

            virtual float GetMouseYImpl() = 0;

        private:
            static Input* s_Instance;
    };
}