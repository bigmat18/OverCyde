#pragma once
#include "../Core/Pch.h"

namespace Engine {
    class ECSystem {
        public:
            ECSystem();
            ~ECSystem();

            void Initialize();
            void Shutdown();
            void Update(); 
            void ProcessInput() {};

            void AddElement(class Entity *element);
            void RemoveElement(class Entity *element);

            void UpdateDeltaTime();
            float_t GetDeltaTime() const { return this->m_deltaTime; };

        private:
            float m_ticksCount;
            float m_deltaTime;
            std::vector<class Entity*> m_entitys;
    };
}