#include "GameObj.h"
#include "Components/Component.h"
#include "Components/RendererComponent.h"

GameObj::GameObj(RendererComponent *renderer = nullptr)
{ 
    this->renderer = renderer; 
    this->data = new GameObjDataWrite({0.0f, 0.0f, 0.0f}, 
                                      {0.0f, 0.0f, 0.0f}, 
                                      {1.0f, 1.0f, 1.0f}, 
                                      0.0f);
}

GameObj::~GameObj() { delete this->renderer; }

void GameObj::AddComponent(Component *component) {
    int order = component->GetUpdateOrder();
    auto iter = this->components.begin();
    for (; iter != this->components.end(); ++iter) {
        if (order < (*iter)->GetUpdateOrder()) break;
    }
    this->components.insert(iter, component);
}

void GameObj::RemoveComponent(Component *component) {
    auto iter = std::find(this->components.begin(), this->components.end(), component);
    if (iter != this->components.end()){
        this->components.erase(iter);
    }
}

void GameObj::Update(float deltaTime) {
    this->renderer->Update(deltaTime);

    for(auto comp : this->components) {
        comp->Update(deltaTime);
    }
}