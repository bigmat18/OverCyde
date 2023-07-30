#ifndef HANDLER_H
#define HANDLER_H

template<class T, 
        typename Tinit, 
        typename... Targs> 
class Handler {
    public:
        Handler() {};
        ~Handler() {};

        virtual Tinit Initialize() = 0;
        virtual void Shutdown() = 0;
        virtual void Update(T *obj, Targs... args) = 0;
};

#endif