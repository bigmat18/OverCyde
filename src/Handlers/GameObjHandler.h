#include "Handler.h"
#include <vector>
#include <iterator>
#include <cstddef>

#ifndef GAME_OBJ_HANDLER_H
#define GAME_OBJ_HANDLER_H

class GameObjHandler : public Handler<class GameObj, void> {
    public:
        GameObjHandler();
        ~GameObjHandler();

        void Initialize() override;
        void Shutdown() override;
        void Update() override;

        void AddElement(class GameObj *element) override;
        void RemoveElement(class GameObj *element) override;

        void UpdateDeltaTime();
        float GetDeltaTime() const { return this->deltaTime; };

    private:
        GLfloat ticksCount;
        GLfloat deltaTime;
        std::vector<class GameObj*> objs;
};

#endif