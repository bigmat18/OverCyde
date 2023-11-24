#include <vector>
#include "Components/Component.h"

#ifndef HANDLER_H
#define HANDLER_H

template<class T, typename Tinit>
class Handler {
    public:
        Handler() {}
        ~Handler() {}

        virtual void AddElement(T *element) = 0;
        virtual void RemoveElement(T *element) = 0;

        virtual void Update() = 0;
        virtual Tinit Initialize() = 0;
        virtual void Shutdown() = 0;
};
#endif