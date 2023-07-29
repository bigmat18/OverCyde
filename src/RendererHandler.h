#include "Handler.h"
#include "ViewMatrix.h"
#include "RendererComponent.h"
#include <vector>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : private Handler<RendererComponent, GLFWwindow*, const float> {
    public:
        RendererHandler();
        ~RendererHandler();

        GLFWwindow *Initialize() override;
        void Shutdown() override;
        void Update(RendererComponent *obj, const float deltaTime) override;

        ViewMatrix* GetView() { return this->view; }

    private: 
        glm::mat4 projection;
        class ViewMatrix *view;
        GLFWwindow *window;
};

#endif