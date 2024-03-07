#pragma once
#include "../Core/Pch.h"
#include "../Core/Types.h"
#include <GL/glew.h>

namespace Core { 
    class Entity {
        public:
            Entity();
            ~Entity();

            void AddComponent(class Component *component);
            void RemoveComponent(class Component *component);

            void Update(float deltaTime);
            void ProcessInput(const class InputState state);

            Vec3f GetPosition() const { return this->m_position; }
            Vec3f GetRotationVec() const { return this->m_rotationVec; }
            Vec3f GetScale() const { return this->m_scale; }
            float GetRotation() const { return this->m_rotation; }


            void SetPosition(Vec3f position) { this->m_position = position; }
            void SetRotationVec(Vec3f rotationVec) { this->m_rotationVec = rotationVec; }
            void SetScale(Vec3f scale) { this->m_scale = scale; }
            void SetRotation(float_t rotation) { this->m_rotation = rotation; }

        private:
            std::vector<class Component*> m_components;
            Vec3f m_position;
            Vec3f m_rotationVec;
            Vec3f m_scale;
            float m_rotation;
    };
}