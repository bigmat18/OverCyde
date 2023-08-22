#include "Handler.h"
#include "../Objs/GameObj.h"
#include <vector>
#include <iterator>
#include <cstddef>

#ifndef GAME_OBJ_HANDLER_H
#define GAME_OBJ_HANDLER_H

class GameObjHandler : public Handler<GameObj, void> {
    public:
        GameObjHandler();
        ~GameObjHandler();

        void Initialize() override;
        void Shutdown() override;

        void UpdateDeltaTime();
        float GetDeltaTime() const { return this->deltaTime; };

    private:
        GLfloat ticksCount;
        GLfloat deltaTime;
};

#endif