#include "Handler.h"
#include "ViewMatrix.h"
#include <vector>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : public Handler {
    public:
        RendererHandler();
        ~RendererHandler();

        void *Initialize() override;
        void Shutdown() override;

        void AddElement(class RendererObj *obj) override;
        void RemoveElement(class RendererObj *obj) override;

        void Update() override;

        ViewMatrix* GetView() { return this->view; }

    private : 
        std::vector<class RendererObj*> objs;
        glm::mat4 projection;
        class ViewMatrix *view;
        GLFWwindow *window;
};

#endif