#include <Renderer/CameraController.h>
#include <Core/Input.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <glm/fwd.hpp>

namespace Engine {
    Camera2DController::Camera2DController(float aspectRatio, bool rotatin) : 
        m_AspectRatio(aspectRatio), m_Rotation(rotatin), 
        m_Camera(glm::vec3(0.0f, 0.0f, 0.0f), 
                 glm::vec3(0.0f, 0.0f, 1.0f),
                 glm::vec3(0.0f, 1.0f, 0.0f),
                 OrthographicCamera::OrthographicData(-m_AspectRatio * m_ZoomLevel, 
				 									  m_AspectRatio * m_ZoomLevel, 
													  -m_ZoomLevel, m_ZoomLevel)) {}


    void Camera2DController::OnUpdate(float deltaTime) {
        glm::vec3 position = m_Camera.GetPosition();
        glm::vec3 up = m_Camera.GetUp();
        

 		if (Input::IsKeyPressed(Key::A)) {
			position.x -= m_CameraTranslationSpeed * deltaTime;

		} else if (Input::IsKeyPressed(Key::D)){
			position.x += m_CameraTranslationSpeed * deltaTime;
		}

		if (Input::IsKeyPressed(Key::W)) {
			position.y += m_CameraTranslationSpeed * deltaTime;

		} else if (Input::IsKeyPressed(Key::S)){
			position.y -= m_CameraTranslationSpeed * deltaTime;
		}

		// if (Input::IsKeyPressed(Key::Q)) {
        //     up.x = glm::cos(glm::degrees(up.x - (m_CameraRotationSpeed * deltaTime)));
        //     up.y = glm::sin(glm::degrees(up.y - (m_CameraRotationSpeed * deltaTime)));
        // }

		// m_Camera.SetUp(up);
		m_Camera.SetPosition(position); 
		m_Camera.RecalculateViewMatrix();  

    }
    
    void Camera2DController::OnEvent(Event& e) {
        
    }
}
