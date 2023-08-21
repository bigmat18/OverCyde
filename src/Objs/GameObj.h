#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H


class GameObj {
    public:
        GameObj();
        ~GameObj();

        void AddComponent(class Component *component);
        void RemoveComponent(class Component *component);

        void Update(float deltaTime);

        glm::vec3 GetPosition() const { return this->position; }
        glm::vec3 GetRotationVec() const { return this->rotationVec; }
        glm::vec3 GetScale() const { return this->scale; }
        GLfloat GetRotation() const { return this->rotation; }
        class RendererComponent *GetRenderer() const { return this->renderer; } 


        void SetPosition(glm::vec3 position) { this->position = position; }
        void SetRotationVec(glm::vec3 rotationVec) { this->rotationVec = rotationVec; }
        void SetScale(glm::vec3 scale) { this->scale = scale; }
        void SetRotation(GLfloat rotation) { this->rotation = rotation; }
        void SetRenderer(class RendererComponent *renderer);

    private:
        std::vector<class Component*> components;
        class RendererComponent *renderer;

        glm::vec3 position;
        glm::vec3 rotationVec;
        glm::vec3 scale;
        GLfloat rotation;
};

#endif