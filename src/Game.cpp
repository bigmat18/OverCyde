#include "Game.h"
#include "RendererHandler.h"
#include "GameObjHandler.h"
#include "Utils/debugging.h"
#include "Utils/global.h"

Game::Game() : isRunning(true) 
{ 
    this->gameObjHandler = new GameObjHandler();
    this->rendererHandler = new RendererHandler();
}

bool Game::Initialize() {
    this->ticksCount = glfwGetTime();
    this->gameObjHandler->Initialize();
    this->window = this->rendererHandler->Initialize();
    return this->window != nullptr;
}

void Game::RunLoop() {
    while(!glfwWindowShouldClose(this->window)) {
        this->ProcessInput();

        glClearColor(DESTRUCT(BACKGROUND_COLOR));
        glClear(GL_COLOR_BUFFER_BIT);

        for(auto it = this->gameObjHandler->begin(), end = this->gameObjHandler->end(); it != end; ++it){
            const auto obj = *it;
            this->UpdateGame(obj);
            this->GenerateOutput(obj->renderer);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Game::ProcessInput() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(this->window, true);
}

void Game::UpdateGame(GameObj *obj) {
    // for(el in gameobj) input->Update()
}

void Game::GenerateOutput(RendererComponent *obj) { 
    this->rendererHandler->Update(obj, this->ticksCount); 
}

void Game::Shutdown() {
    this->rendererHandler->Shutdown();
    this->gameObjHandler->Shutdown();
}

void Game::LoadData() {}

void Game::UnLoadData() {}