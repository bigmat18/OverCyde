#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
    private:
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;

        GLfloat Yaw;
        GLfloat Pitch;

        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        float lastX;
        float lastY;
        float init;

        void updateCameraVectors();

    public:
        Camera(const GLfloat WIDTH, const GLfloat HEIGTH, const GLfloat fov);

        GLfloat GetZoom() const { return this->Zoom; };
        glm::vec3 GetPosizion() const { return this->Position; };
        glm::mat4 GetViewMatrix() const { return glm::lookAt(this->Position, this->Position + this->Front, this->Up); };

        void ProcessInput(GLFWwindow *window, float deltaTime);
        void MouseCallBack(double xpos, double ypos);
        void ScrollCallBack(float yoffset);
};

#endif