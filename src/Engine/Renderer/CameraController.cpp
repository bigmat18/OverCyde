#include "CameraController.h"
#include "../Core/Input.h"
#include "glm/fwd.hpp"

namespace Engine {
    Camera2DController::Camera2DController(float aspectRatio, bool rotatin) : 
        m_AspectRatio(aspectRatio), m_Rotation(rotatin), 
        m_Camera({0.0f, 0.0f, 0.0f}, 
                 {0.0f, 0.0f, 1.0f},
                 {0.0f, 1.0f, 0.0f},
                 {-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel}) {}


    void Camera2DController::OnUpdate(float deltaTime) {
        glm::vec3 position = m_Camera.GetPosition();
        glm::vec3 up = m_Camera.GetUp();
        

 		if (Input::IsKeyPressed(Key::A)) {
			position.x -= m_CameraTranslationSpeed * deltaTime;
			position.y -= m_CameraTranslationSpeed * deltaTime;

		} else if (Input::IsKeyPressed(Key::D)){
			position.x += m_CameraTranslationSpeed * deltaTime;
			position.y += m_CameraTranslationSpeed * deltaTime;
		}

		if (Input::IsKeyPressed(Key::W)) {
			position.x += m_CameraTranslationSpeed * deltaTime;
			position.y += m_CameraTranslationSpeed * deltaTime;

		} else if (Input::IsKeyPressed(Key::S)){
			position.x -= m_CameraTranslationSpeed * deltaTime;
			position.y -= m_CameraTranslationSpeed * deltaTime;
		}

		if (Input::IsKeyPressed(Key::Q)) {
            up.x = glm::cos(glm::degrees(up.x - (m_CameraRotationSpeed * deltaTime)));
            up.y = glm::sin(glm::degrees(up.y - (m_CameraRotationSpeed * deltaTime)));
        }

		m_Camera.SetUp(up);
		m_Camera.SetPosition(position);   

    }
    
    void Camera2DController::OnEvent(Event& e) {
        
    }
}
