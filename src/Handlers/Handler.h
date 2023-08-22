#include <vector>

#ifndef HANDLER_H
#define HANDLER_H

template<class T, typename Tinit>
class Handler {
    public:
        Handler();
        ~Handler();

        virtual void AddElement(T *element);
        virtual void RemoveElement(T *element);

        virtual Tinit Initialize() = 0;
        virtual void Shutdown() = 0;
        virtual void Update() const;

    protected:
        std::vector<T*> objs;
};
#endif