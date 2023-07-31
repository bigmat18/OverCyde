#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H

struct GameObjData {
    protected:
        glm::vec3 position;
        glm::vec3 rotationVec;
        glm::vec3 scale;
        GLfloat rotation;

    public:
        GameObjData(glm::vec3 position, glm::vec3 rotationVec, glm::vec3 scale, GLfloat rotation) : position(position),
                                                                                                    rotationVec(rotationVec),
                                                                                                    scale(scale),
                                                                                                    rotation(rotation) {}

        glm::vec3 GetPosition() const { return this->position; }
        glm::vec3 GetRotationVec() const { return this->rotationVec; }
        glm::vec3 GetScale() const { return this->scale; }
        GLfloat GetRotation() const { return this->rotation; }
};

struct GameObjDataWrite : GameObjData {
    public:
        GameObjDataWrite(glm::vec3 position, 
                         glm::vec3 rotationVec, 
                         glm::vec3 scale, 
                         GLfloat rotation) : GameObjData(position, rotationVec, scale, rotation) {};

        void SetPosition(glm::vec3 position) { this->position = position; }
        void SetRotationVec(glm::vec3 rotationVec) { this->rotationVec = rotationVec; }
        void SetScale(glm::vec3 scale) { this->scale = scale; }
        void SetRotation(GLfloat rotation) { this->rotation = rotation; }
};

class GameObj {
    public:
        GameObj(class RendererComponent *renderer);
        ~GameObj();

        void AddComponent(class Component *component);
        void RemoveComponent(class Component *component);

        void Update(float deltaTime);

        struct GameObjDataWrite *GetGameObjDataWrite() const { return this->data; }
        struct GameObjData *GetGameObjData() const { 
            return static_cast<GameObjData*>(this->data); 
        }

        class RendererComponent *renderer;
    private:
        std::vector<class Component*> components;
        struct GameObjDataWrite *data;
};

#endif