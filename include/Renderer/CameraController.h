#pragma once
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Camera.h"

namespace Engine {

    class Camera2DController {
        public:
            Camera2DController(float aspectRatio, bool roation = false);

            void OnUpdate(float deltaTime);
            void OnEvent(Event &e);

            glm::mat4 GetProjectionViewMatrix() { 
                return m_Camera.GetProjectionViewMatrix(); 
            }

            bool OnMouseScrolled(MouseScrolledEvent& e);
            bool OnWindowResized(WindowResizeEvent& e);
        private:

            float m_CameraTranslationSpeed = 2.0f;
            float m_CameraRotationSpeed = 1.0f;
            float m_ZoomLevel = 1.0f;

            float m_AspectRatio;
            bool m_Rotation;
            OrthographicCamera m_Camera;
    };
}
