#include "../GameObj.h"

#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    public:
        Component(class GameObj* gameObj, int updateOrder = 0) : gameObj(gameObj),
                                                                 updateOrder(updateOrder)
        { this->gameObj->AddComponent(this); }

        ~Component() { this->gameObj->RemoveComponent(this); }

        virtual void Update(int deltaTime);
        int GetUpdateOrder() const { return this->updateOrder; }

    protected:
        class GameObj* gameObj;
        int updateOrder;
};

#endif