#include <vector>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H

class GameObj {
    public:
        GameObj(class RendererComponent *renderer = nullptr);
        ~GameObj();

        void AddComponent(class Component *component);
        void RemoveComponent(class Component *component);

        void Update(float deltaTime);

        class RendererComponent *renderer;
    private:
        std::vector<class Component*> components;
};

#endif