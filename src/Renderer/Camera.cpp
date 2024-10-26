#include <Renderer/Camera.h>

namespace Engine {
    Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up, glm::mat4 projection) : 
        m_ProjectionMatrix(projection), m_Position(position), m_Front(front), m_Up(up)
    {
        this->m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
        this->m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    void Camera::RecalculateViewMatrix() {
        this->m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
        this->m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    ////////////////////////////////////////////////////////////
    //////////////////// OrthographicCamera ////////////////////
    ///////////////////////////////////////////////////////////
    OrthographicCamera::OrthographicCamera(glm::vec3 position, 
                                           glm::vec3 front, 
                                           glm::vec3 up,
                                           OrthographicData data) : 
        Camera(position, front, up, 
               glm::ortho(data.Left, 
                          data.Right, 
                          data.Bottom, 
                          data.Top, 
                          -1.0f, 1.0f)) 
    { /*...*/ }

    void OrthographicCamera::RecalculateProjectionMatrix() {
        this->m_ProjectionMatrix = glm::ortho(m_Data.Left, m_Data.Right, m_Data.Bottom, m_Data.Top, -1.0f, -1.0f);
        this->m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    ////////////////////////////////////////////////////////////
    //////////////////// PerspectiveCamera /////////////////////
    ///////////////////////////////////////////////////////////
    PerspectiveCamera::PerspectiveCamera(glm::vec3 position, 
                                         glm::vec3 front, 
                                         glm::vec3 up,
                                         PerspectiveData data) : 
        Camera(position, front, up, 
               glm::perspective(glm::radians(data.Fov), 
                                data.AspectRatio, 
                                data.NearClip, 
                                data.FarClip)) 
    { /*...*/ }

    void PerspectiveCamera::RecalculateProjectionMatrix() {
        this->m_ProjectionMatrix = glm::perspective(glm::radians(m_Data.Fov), m_Data.AspectRatio, m_Data.NearClip, m_Data.FarClip);
        this->m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }
}