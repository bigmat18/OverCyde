#include <vector>
#include <glm/glm.hpp>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H

struct GameObjData {
    glm::vec3 position;
    glm::vec3 rotationVec;
    glm::vec3 scale;
    GLfloat rotation;
};

class GameObj {
    public:
        GameObj(class RendererComponent *renderer = nullptr);
        ~GameObj();

        void AddComponent(class Component *component);
        void RemoveComponent(class Component *component);

        void Update(float deltaTime);
        
        struct GameObjData GetGameObjData() const { 
            return (struct GameObjData){this->position, this->rotationVec, this->scale, this->rotation}; 
        };

        class RendererComponent *renderer;
    private:
        std::vector<class Component*> components;
        
        glm::vec3 position;
        glm::vec3 rotationVec;
        glm::vec3 scale;
        GLfloat rotation;
};

#endif