#include "Game.h"
#include "RendererHandler.h"
#include "Utils/debugging.h"
#include "Utils/global.h"

Game::Game() : window(nullptr),
               isRunning(true) 
{ 
    this->rendererHandler = new RendererHandler();
}

bool Game::Initialize() {
    this->rendererHandler->Initialize(this->window);
    this->ticksCount = glfwGetTime();
    return true;
}

void Game::RunLoop() {
    while(!glfwWindowShouldClose(this->window)) {
        this->ProcessInput();
        this->UpdateGame();
        this->GenerateOutput();
    }
}

void Game::ProcessInput() {}

void Game::UpdateGame() {}

void Game::GenerateOutput() { 
    this->rendererHandler->Update(this->window); 
}

void Game::Shutdown() {
    this->rendererHandler->Shutdown(this->window);
}

void Game::LoadData() {}

void Game::UnLoadData() {}