#pragma once
#include "../Events/Event.h"
#include "Camera.h"

namespace Engine {
    class Camera2DController {
        public:
            Camera2DController(float aspectRatio, bool rotatin = false);

            void OnUpdate(float deltaTime);
            void OnEvent(Event &e);

        private:
            float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
            float m_ZoomLevel = 1.0f;

            float m_AspectRatio;
            float m_Rotation;
            OrthographicCamera m_Camera;
    };
}
