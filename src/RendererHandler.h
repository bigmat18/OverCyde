#include "Handler.h"
#include "ViewMatrix.h"
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : Handler {
    public:
        RendererHandler();
        ~RendererHandler();

        bool Initialize(GLFWwindow *window);
        void Shutdown(GLFWwindow *window);

        void AddElement(class RendererObj *obj);
        void RemoveElement(class RendererObj *obj);

        void Update(GLFWwindow *window);

        ViewMatrix* GetView() { return &this->view; }

    private : 
        std::vector<class RendererObj *> objs;
        glm::mat4 projection;
        class ViewMatrix view;
};

#endif