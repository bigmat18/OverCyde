#include "GameObjHandler.h"
#include <GLFW/glfw3.h>
#include <iostream>

GameObjHandler::GameObjHandler() : Handler(),
                                   ticksCount(0.0f),
                                   deltaTime(0.0f) {}

GameObjHandler::~GameObjHandler() {}

void GameObjHandler::Initialize() { this->ticksCount = glfwGetTime(); }

void GameObjHandler::Shutdown() {}

void GameObjHandler::Update() const {
    for(auto obj : this->objs) {
        obj->Update(this->deltaTime);
    }
}

void GameObjHandler::UpdateDeltaTime() {
    this->deltaTime = (glfwGetTime() - this->ticksCount) / 1000.0f;
    this->ticksCount = glfwGetTime();
    if (this->deltaTime > 0.05f) this->deltaTime = 0.05f;
}