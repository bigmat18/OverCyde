#include "GameObjHandler.h"
#include "GameObj.h"
#include <GLFW/glfw3.h>
#include <iostream>

GameObjHandler::GameObjHandler() : Handler(),
                                   ticksCount(0.0f),
                                   deltaTime(0.0f) {}

GameObjHandler::~GameObjHandler() {
    for (auto obj : this->objs)
        delete obj;
}

void GameObjHandler::Initialize() { this->ticksCount = glfwGetTime(); }

void GameObjHandler::Shutdown() {}

void GameObjHandler::Update() {
    for(auto obj : this->objs) {
        obj->Update(this->deltaTime);
    }
}

void GameObjHandler::UpdateDeltaTime() {
    this->deltaTime = (glfwGetTime() - this->ticksCount) / 1000.0f;
    this->ticksCount = glfwGetTime();
    if (this->deltaTime > 0.05f) this->deltaTime = 0.05f;
}

void GameObjHandler::AddElement(GameObj *element) {
    this->objs.push_back(element);
}

void GameObjHandler::RemoveElement(GameObj *element) {
    auto iter = std::find(this->objs.begin(), this->objs.end(), element);
    if (iter != this->objs.end()) {
        std::iter_swap(iter, this->objs.end() - 1);
        this->objs.pop_back();
    }
}