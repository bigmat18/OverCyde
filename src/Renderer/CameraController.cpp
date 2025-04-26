#include <Renderer/CameraController.h>
#include <Input/Input.h>

#include <Core/Events/ApplicationEvent.h>
#include <Core/Events/MouseEvent.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/fwd.hpp>

namespace Engine {
	
	////////////////////////////////////////////////////////////
    //////////////////// Camera2DController ///////////////////
    ///////////////////////////////////////////////////////////
    Camera2DController::Camera2DController(float aspectRatio, bool roation) : 
        m_AspectRatio(aspectRatio), m_Rotation(roation), 
        m_Camera(glm::vec3(0.0f, 0.0f, 0.0f), 
                 glm::vec3(0.0f, 0.0f, -1.0f),
                 glm::vec3(0.0f, 1.0f, 0.0f),
                 OrthographicCamera::OrthographicData(-m_AspectRatio * m_ZoomLevel, 
				 									  m_AspectRatio * m_ZoomLevel, 
													  -m_ZoomLevel, 
													  m_ZoomLevel)) {}


    void Camera2DController::OnUpdate(float deltaTime) {
        glm::vec3 position = m_Camera.GetPosition();
		glm::vec3 front = m_Camera.GetFront();
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

		if(m_Rotation) {
			Mat4f rotation(1.0);
			if (Input::IsKeyPressed(Key::Q)) {
				rotation = glm::rotate(Mat4f(1.0), -m_CameraRotationSpeed * deltaTime, Vec3f(0.0, 0.0, 1.0));
			}
			if (Input::IsKeyPressed(Key::E)) {
				rotation = glm::rotate(Mat4f(1.0), m_CameraRotationSpeed * deltaTime, Vec3f(0.0, 0.0, 1.0));
			}

			up = rotation * Vec4f(up, 0.0f);
			front = rotation * Vec4f(front, 0.0f);
		}

		m_Camera.SetUp(up);
		m_Camera.SetPosition(position); 
		m_Camera.SetFront(front);
		m_Camera.RecalculateViewMatrix();  

    }
    
    void Camera2DController::OnEvent(Event& e) {
        EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_FUN(Camera2DController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_FUN(Camera2DController::OnWindowResized));
    }

	bool Camera2DController::OnMouseScrolled(MouseScrolledEvent& e) {
		return true;
	}

    bool Camera2DController::OnWindowResized(WindowResizeEvent& e) {
		m_AspectRatio = static_cast<float>(e.GetWidth()) / static_cast<float>(e.GetHeigth());
		m_Camera.SetLeft(-m_AspectRatio * m_ZoomLevel);
        m_Camera.SetRight(m_AspectRatio * m_ZoomLevel);
        m_Camera.SetBottom(-m_ZoomLevel);
        m_Camera.SetTop(m_ZoomLevel);
		m_Camera.RecalculateProjectionMatrix();
	}

	////////////////////////////////////////////////////////////
    //////////////////// Camera3DController ///////////////////
    ///////////////////////////////////////////////////////////
}
