#include <vector>

#ifndef GAME_OBJ_HANDLER_H
#define GAME_OBJ_HANDLER_H

class ECSystem {
    public:
        ECSystem();
        ~ECSystem();

        void Initialize();
        void Shutdown();
        void Update(); 

        void AddElement(class Entity *element);
        void RemoveElement(class Entity *element);

        void UpdateDeltaTime();
        float_t GetDeltaTime() const { return this->m_deltaTime; };

    private:
        float_t m_ticksCount;
        float_t m_deltaTime;
        std::vector<class Entity*> m_entitys;
};

#endif
