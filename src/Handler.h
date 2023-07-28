#include <GLFW/glfw3.h>

#ifndef HANDLER_H
#define HANDLER_H

class Handler {
    public:
        Handler() {};
        ~Handler() {};

        virtual bool Initialize(GLFWwindow *window) = 0;
        virtual void Shutdown(GLFWwindow *window) = 0;

        virtual void AddElement(class RendererObj *obj) {};
        virtual void RemoveElement(class RendererObj *obj) {};

        virtual void Update(GLFWwindow *window) = 0;
};

#endif