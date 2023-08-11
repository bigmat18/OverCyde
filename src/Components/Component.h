#include <GL/glew.h>
#include "../GameObj.h"

#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    public:
        Component(class GameObj *gameObj, GLshort updateOrder = 0) : gameObj(gameObj),
                                                                     updateOrder(updateOrder)
        { this->gameObj->AddComponent(this); }

        Component() {};

        virtual ~Component() { this->gameObj->RemoveComponent(this); }

        virtual void Update(int deltaTime) {};
        int GetUpdateOrder() const { return this->updateOrder; }

    protected:
        class GameObj* gameObj;
        GLshort updateOrder;
};

#endif