#include "Handler.h"
#include "ViewMatrix.h"
#include <vector>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererHandler : public Handler {
    public:
        RendererHandler();
        ~RendererHandler();

        bool Initialize(GLFWwindow *window) override;
        void Shutdown(GLFWwindow *window) override;

        void AddElement(class RendererObj *obj) override;
        void RemoveElement(class RendererObj *obj) override;

        void Update(GLFWwindow *window) override;

        ViewMatrix* GetView() { return this->view; }

    private : 
        std::vector<class RendererObj*> objs;
        glm::mat4 projection;
        class ViewMatrix *view;
};

#endif