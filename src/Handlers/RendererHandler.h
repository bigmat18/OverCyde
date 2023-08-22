#include "Handler.h"
#include "ViewMatrix.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : private Handler<class RendererComponent, GLFWwindow*> {
    public:
        RendererHandler(class ViewMatrix *view);
        ~RendererHandler();

        GLFWwindow *Initialize() override;
        void Shutdown() override;
        void Update() const override;

    private:
        glm::mat4 projection;
        class ViewMatrix *view;
        GLFWwindow *window;
};

#endif