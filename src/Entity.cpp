#include "Entity.h"
#include "Components/Component.h"
#include "Components/RendererComponent.h"
#include "ECSHandler.h"

Entity::Entity() : m_position(glm::vec3(0.0f, 0.0f, 0.0f)),
                   m_rotationVec(glm::vec3(1.0f, 1.0f, 1.0f)),
                   m_scale(glm::vec3(1.0f, 1.0f, 1.0f)),
                   m_rotation(0.0f) {} 

Entity::~Entity() { 
    for(auto component : this->m_components) {
        delete component;
    }
}

void Entity::AddComponent(Component *component) {
    int order = component->GetUpdateOrder();
    auto iter = this->m_components.begin();
    for (; iter != this->m_components.end(); ++iter) {
        if (order < (*iter)->GetUpdateOrder()) break;
    }
    this->m_components.insert(iter, component);
}

void Entity::RemoveComponent(Component *component) {
    auto iter = std::find(this->m_components.begin(), this->m_components.end(), component);
    if (iter != this->m_components.end()){
        this->m_components.erase(iter);
    }
}

void Entity::Update(float deltaTime) {
    for(auto comp : this->m_components) {
        comp->Update(deltaTime);
    }
}
