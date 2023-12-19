#include "ECSystem.h"
#include "Entity.h"
#include "SDL.h"
#include <GLFW/glfw3.h>

ECSystem::ECSystem() : m_ticksCount(0.0f), 
                       m_deltaTime(0.0f) {}

ECSystem::~ECSystem() {
  for (auto obj : this->m_entitys)
    delete obj;
}

void ECSystem::Initialize() { 
    check(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0, exit(1), 0);
    this->m_ticksCount = SDL_GetTicks();
}

void ECSystem::Shutdown() {
    SDL_Quit();
}

void ECSystem::Update() {
  for (auto obj : this->m_entitys) {
    obj->Update(this->m_deltaTime);
  }
}

void ECSystem::UpdateDeltaTime() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->m_ticksCount + 16));
    
    this->m_deltaTime = (SDL_GetTicks() - this->m_ticksCount) / 1000.0f;
    this->m_ticksCount = SDL_GetTicks();

    if (this->m_deltaTime > 0.05f)
        this->m_deltaTime = 0.05f;
}

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
