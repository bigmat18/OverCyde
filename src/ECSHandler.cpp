#include "ECSHandler.h"
#include "Entity.h"
#include <GLFW/glfw3.h>

ECSHandler::ECSHandler()
    : Handler(), m_ticksCount(0.0f), m_deltaTime(0.0f) {}

ECSHandler::~ECSHandler() {
  for (auto obj : this->m_entitys)
    delete obj;
}

void ECSHandler::Initialize() { this->m_ticksCount = glfwGetTime(); }

void ECSHandler::Shutdown() {}

void ECSHandler::Update() {
  for (auto obj : this->m_entitys) {
    obj->Update(this->m_deltaTime);
  }
}

void ECSHandler::UpdateDeltaTime() {
  this->m_deltaTime = (glfwGetTime() - this->m_ticksCount) / 1000.0f;
  this->m_ticksCount = glfwGetTime();
  if (this->m_deltaTime > 0.05f)
    this->m_deltaTime = 0.05f;
}

void ECSHandler::AddElement(Entity *element) {
  this->m_entitys.push_back(element);
}

void ECSHandler::RemoveElement(Entity *element) {
  auto iter = std::find(this->m_entitys.begin(), this->m_entitys.end(), element);
  if (iter != this->m_entitys.end()) {
    std::iter_swap(iter, this->m_entitys.end() - 1);
    this->m_entitys.pop_back();
  }
}
