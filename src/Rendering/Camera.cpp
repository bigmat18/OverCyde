#include "Camera.h"
#include "../Handlers/ViewMatrix.h"
#include "../Utils/global.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

Camera::Camera(const float width, const float height, const float fov, ViewMatrix *view) : Yaw(YAW),
                                                                                           Pitch(PITCH),
                                                                                           MovementSpeed(SPEED),
                                                                                           MouseSensitivity(SENSITIVITY),
                                                                                           Zoom(ZOOM),
                                                                                           init(false),
                                                                                           view(view)
{
    this->Position = glm::vec3(0.0f, 0.0f, 2.0f);
    this->Front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->Up = glm::vec3(0.0f, 1.0f, 0.0f);
    this->updateCameraVectors();
}

void Camera::ProcessInput(GLFWwindow *window, float deltaTime){
    float cameraSpeed = this->MovementSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        this->Position += cameraSpeed * this->Front;
        this->Position += cameraSpeed * this->Up;
    } 
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        this->Position -= cameraSpeed * this->Front;
        this->Position -= cameraSpeed * this->Up;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        this->Position -= glm::normalize(glm::cross(this->Front, this->Up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        this->Position += glm::normalize(glm::cross(this->Front, this->Up)) * cameraSpeed;
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