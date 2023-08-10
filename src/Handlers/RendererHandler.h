#include "Handler.h"
#include "ViewMatrix.h"
#include <vector>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : private Handler<class RendererComponent, GLFWwindow*> {
    public:
        RendererHandler();
        ~RendererHandler();

        GLFWwindow *Initialize() override;
        void Shutdown() override;
        void Update(class RendererComponent *obj) override;

        class ViewMatrix* GetViewMatrix() const { return this->view; };

    private: 
        glm::mat4 projection;
        class ViewMatrix *view;
        GLFWwindow *window;
};

#endif