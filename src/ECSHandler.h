#include "Handler.h"
#include <vector>

#ifndef GAME_OBJ_HANDLER_H
#define GAME_OBJ_HANDLER_H

class ECSHandler : public Handler<class Entity, void> {
    public:
        ECSHandler();
        ~ECSHandler();

        void Initialize() override;
        void Shutdown() override;
        void Update() override;

        void AddElement(class Entity *element) override;
        void RemoveElement(class Entity *element) override;

        void UpdateDeltaTime();
        float_t GetDeltaTime() const { return this->m_deltaTime; };

    private:
        float_t m_ticksCount;
        float_t m_deltaTime;
        std::vector<class Entity*> m_entitys;
};

#endif
