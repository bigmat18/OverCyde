#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

Camera::Camera(const float width, const float height, const float fov) : Yaw(YAW),
                                                                         Pitch(PITCH),
                                                                         MovementSpeed(SPEED),
                                                                         MouseSensitivity(SENSITIVITY),
                                                                         Zoom(ZOOM),
                                                                         init(false)
{
    this->Position = glm::vec3(0.0f, 0.0f, 3.0f);
    this->Front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->Up = glm::vec3(0.0f, 1.0f, 0.0f);
    this->updateCameraVectors();
}

void Camera::ProcessInput(GLFWwindow *window, float deltaTime){
    float cameraSpeed = this->MovementSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        this->Position += cameraSpeed * this->Front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        this->Position -= cameraSpeed * this->Front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        this->Position -= glm::normalize(glm::cross(this->Front, this->Up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        this->Position += glm::normalize(glm::cross(this->Front, this->Up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        this->Position += cameraSpeed * this->Up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        this->Position -= cameraSpeed * this->Up;
}

void Camera::MouseCallBack(double xpos, double ypos){

    if (!init) {
        lastX = xpos;
        lastY = ypos;
        init = true;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    xoffset *= this->MouseSensitivity;
    yoffset *= this->MouseSensitivity;

    this->Yaw   += xoffset;
    this->Pitch += yoffset;

    if (this->Pitch > 89.0f) this->Pitch = 89.0f;
    if (this->Pitch < -89.0f) this->Pitch = -89.0f;

    this->updateCameraVectors();
}

void Camera::ScrollCallBack(float yoffset){
    this->Zoom -= (float)yoffset;
    if (this->Zoom < 1.0f) this->Zoom = 1.0f;
    if (this->Zoom > 45.0f) this->Zoom = 45.0f;
}

void Camera::updateCameraVectors(){
    glm::vec3 front;
    front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    front.y = sin(glm::radians(this->Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(this->Pitch));
    Front = glm::normalize(front);
}
