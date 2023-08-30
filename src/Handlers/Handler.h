#include <vector>
#include "../Components/Component.h"

#ifndef HANDLER_H
#define HANDLER_H

template<class T, typename Tinit>
class Handler {
    public:
        Handler() {}
        
        ~Handler() {
            for (auto obj : this->objs)
                delete obj;
        }

        virtual void AddElement(T *element) {
            this->objs.push_back(element);
        }

        virtual void RemoveElement(T *element) {
            auto iter = std::find(this->objs.begin(), this->objs.end(), element);
            if (iter != this->objs.end()) {
                std::iter_swap(iter, this->objs.end() - 1);
                this->objs.pop_back();
            }
        }

        virtual void Update() const = 0;
        virtual Tinit Initialize() = 0;
        virtual void Shutdown() = 0;

    protected:
        std::vector<T*> objs;
};
#endif