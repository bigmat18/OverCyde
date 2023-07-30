#include "GameObjHandler.h"
#include <GLFW/glfw3.h>
#include <iostream>

GameObjHandler::GameObjHandler() : deltaTime(0.0f), 
                                   ticksCount(0.0f) {}

GameObjHandler::~GameObjHandler() {}

void GameObjHandler::Initialize() {
    this->ticksCount = glfwGetTime();
}

void GameObjHandler::Shutdown() {
    for(auto obj : this->objs) delete obj;
}

void GameObjHandler::Update(GameObj *obj) {
    obj->Update(this->deltaTime);
}

void GameObjHandler::AddGameObj(GameObj *obj) {
    this->objs.emplace_back(obj);
}

void GameObjHandler::RemoveGameObj(GameObj *obj) {
    auto iter = std::find(this->objs.begin(), this->objs.end(), obj);
    if (iter != this->objs.end()) {
        std::iter_swap(iter, this->objs.end() - 1);
        this->objs.pop_back();
    }
}

void GameObjHandler::UpdateDeltaTime() {
    this->deltaTime = (glfwGetTime() - this->ticksCount) / 1000.0f;
    this->ticksCount = glfwGetTime();

    std::cout << "FPS: " << 1.0f / this->deltaTime << std::endl;

    if (this->deltaTime > 0.05f) this->deltaTime = 0.05f;
}