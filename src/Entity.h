#include <cmath>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H


class Entity {
    public:
        Entity();
        ~Entity();

        void AddComponent(class Component *component);
        void RemoveComponent(class Component *component);

        void Update(float deltaTime);
        void ProcessInput(const class InputState state);

        glm::vec3 GetPosition() const { return this->m_position; }
        glm::vec3 GetRotationVec() const { return this->m_rotationVec; }
        glm::vec3 GetScale() const { return this->m_scale; }
        GLfloat GetRotation() const { return this->m_rotation; }


        void SetPosition(glm::vec3 position) { this->m_position = position; }
        void SetRotationVec(glm::vec3 rotationVec) { this->m_rotationVec = rotationVec; }
        void SetScale(glm::vec3 scale) { this->m_scale = scale; }
        void SetRotation(float_t rotation) { this->m_rotation = rotation; }

    private:
        std::vector<class Component*> m_components;
        glm::vec3 m_position;
        glm::vec3 m_rotationVec;
        glm::vec3 m_scale;
        float_t m_rotation;
};

#endif
