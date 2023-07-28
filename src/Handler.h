#include <GLFW/glfw3.h>

#ifndef HANDLER_H
#define HANDLER_H

class Handler {
    public:
        Handler() {};
        ~Handler() {};

        virtual void *Initialize() = 0;
        virtual void Shutdown() = 0;

        virtual void AddElement(class RendererObj *obj) {};
        virtual void RemoveElement(class RendererObj *obj) {};

        virtual void Update() = 0;
};

#endif