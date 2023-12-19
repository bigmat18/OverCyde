#include "Components/RendererComponent.h"
#include "Rendering/ViewMatrix.h"
#include "RendererSystem.h"
#include "SDL_video.h"
#include "Utils/Global.h"
#include <SDL.h>

RendererSystem::RendererSystem(ViewMatrix *view) : m_view(view) {
    this->m_projection = glm::perspective(glm::radians(ZOOM),
                                        (float)(WIDTH) / (float)(HEIGHT),
                                        0.1f, 100.0f);
}

RendererSystem::~RendererSystem() { delete this->m_view; }

void RendererSystem::Initialize() {

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);


    this->m_window = (SDL_Window*)scp(SDL_CreateWindow(TITLE,
                                                       static_cast<int>(X_OFFSET), 
                                                       static_cast<int>(Y_OFFSET), 
                                                       static_cast<int>(WIDTH), 
                                                       static_cast<int>(HEIGHT), 
                                                       SDL_WINDOW_OPENGL)); 

    this->m_context = static_cast<SDL_GLContext*>(SDL_GL_CreateContext(this->m_window));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RendererSystem::Shutdown() { glfwTerminate(); }

void RendererSystem::Update() {
    glClearColor(HEX_COLOR(BACKGROUND_COLOR));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto obj : this->m_objs){
        obj->Draw(this->m_window, this->m_projection, this->m_view->GetView());
    }
}

void RendererSystem::AddElement(RendererComponent *element) {
    this->m_objs.push_back(element);
}

void RendererSystem::RemoveElement(RendererComponent *element) {
    auto iter = std::find(this->m_objs.begin(), this->m_objs.end(), element);
    if (iter != this->m_objs.end()) {
        std::iter_swap(iter, this->m_objs.end() - 1);
        this->m_objs.pop_back();
    }
}
