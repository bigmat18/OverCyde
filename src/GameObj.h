#include <vector>
#include <glm/glm.hpp>

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

        glm::vec3 position;
        glm::vec3 rotationVec;
        glm::vec3 scale;
        GLfloat rotation;

    private:
        std::vector<class Component*> components;
};

#endif