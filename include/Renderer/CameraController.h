#pragma once
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Camera.h"

namespace Engine {

    class CameraController {
        public: 
            virtual void OnUpdate(float deltaTime);
            virtual void OnEvent(Event& e);

            virtual glm::mat4 GetProjectionViewMatrix() const;
    };

    class Camera2DController : public CameraController {
        public:
            Camera2DController(float aspectRatio, bool rotation = false);

            void OnUpdate(float deltaTime) override;
            void OnEvent(Event &e) override;

            glm::mat4 GetProjectionViewMatrix() const override{ 
                return m_Camera.GetProjectionViewMatrix(); 
            }

        private:
            bool OnMouseScrolled(MouseScrolledEvent& e);
            bool OnWindowResized(WindowResizeEvent& e);

            float m_CameraTranslationSpeed = 2.0f;
            float m_CameraRotationSpeed = 1.0f;
            float m_ZoomLevel = 1.0f;

            float m_AspectRatio;
            bool m_Rotation;
            OrthographicCamera m_Camera;
    };

    class Camera3DController : public CameraController {
        public: 
            Camera3DController(float aspectRatio);

            void OnUpdate(float deltaTime) override;
            void OnEvent(Event &e) override;

            glm::mat4 GetProjectionViewMatrix() const override{ 
                return m_Camera.GetProjectionViewMatrix(); 
            }

        private:
            float m_CameraTranslationSpeed = 2.0f;
            float m_CameraRotationSpeed = 1.0f;
            float m_ZoomLevel = 1.0f;

            float m_Yaw, m_Pitch, m_LastX, m_LastY;
            PerspectiveCamera m_Camera;
    };
}