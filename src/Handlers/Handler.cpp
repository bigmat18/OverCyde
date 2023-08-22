#include "Handler.h"

template <class T, typename Tinit>
Handler<T, Tinit>::Handler() {};

template <class T, typename Tinit>
Handler<T, Tinit>::~Handler() {
    for(auto obj : this->objs) 
        delete obj; 
}

template <class T, typename Tinit>
void Handler<T, Tinit>::Update() const {
    for(auto obj : this->objs)
        obj->Update(this->deltaTime);
}

template <class T, typename Tinit>
void Handler<T, Tinit>::AddElement(T *element) {
    this->objs.push_back(element);
}

template <class T, typename Tinit>
void Handler<T, Tinit>::RemoveElement(T *element){
    auto iter = std::find(this->objs.begin(), this->objs.end(), element);
    if (iter != this->objs.end()) {
        std::iter_swap(iter, this->objs.end() - 1);
        this->objs.pop_back();
    }
}