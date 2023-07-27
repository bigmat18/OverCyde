#include <GLFW/glfw3.h>

#ifndef HANDLER_H
#define HANDLER_H

class Handler {
    public:
        Handler() {};
        ~Handler() {};

        bool Initialize();
        void Shutdown();

        virtual void AddElement();
        virtual void RemoveElement();
        virtual void Update();
};

#endif