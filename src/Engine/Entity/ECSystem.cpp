#include "ECSystem.h"
#include "Entity.h"
#include <GLFW/glfw3.h>

namespace Core {
  ECSystem::ECSystem() : m_ticksCount(0.0f), 
                         m_deltaTime(0.0f) {}

  ECSystem::~ECSystem() {
    for (auto obj : this->m_entitys)
      delete obj;
  }

  void ECSystem::Initialize() {}

  void ECSystem::Shutdown() {}

  void ECSystem::Update() {
    for (auto obj : this->m_entitys) {
      obj->Update(this->m_deltaTime);
    }
  }

  void ECSystem::UpdateDeltaTime() {}

  void ECSystem::AddElement(Entity *element) {
    this->m_entitys.push_back(element);
  }

  void ECSystem::RemoveElement(Entity *element) {
    auto iter = std::find(this->m_entitys.begin(), this->m_entitys.end(), element);
    if (iter != this->m_entitys.end()) {
      std::iter_swap(iter, this->m_entitys.end() - 1);
      this->m_entitys.pop_back();
    }
  }
}