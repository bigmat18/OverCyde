#pragma once
#include "../Events/Event.h"
#include "Camera.h"

namespace Engine {

    class Camera2DController {
        public:
            Camera2DController(float aspectRatio, bool rotatin = false);

            void OnUpdate(float deltaTime);
            void OnEvent(Event &e);

            glm::mat4 GetProjectionViewMatrix() { 
                return m_Camera.GetProjectionViewMatrix(); 
            }

        private:
            float m_CameraTranslationSpeed = 2.0f, m_CameraRotationSpeed = 180.0f;
            float m_ZoomLevel = 1.0f;

            float m_AspectRatio;
            bool m_Rotation;
            OrthographicCamera m_Camera;
    };
}
