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
    this->ticksCount = glfwGetTime();
    return this->rendererHandler->Initialize(this->window);
}

void Game::RunLoop() {
    while(!glfwWindowShouldClose(this->window)) {
        this->ProcessInput();
        this->UpdateGame();
        this->GenerateOutput();
    }
}

void Game::ProcessInput() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(this->window, true);
}

void Game::UpdateGame() {}

void Game::GenerateOutput() { 
    this->rendererHandler->Update(this->window); 
}

void Game::Shutdown() {
    this->rendererHandler->Shutdown(this->window);
}

void Game::LoadData() {}

void Game::UnLoadData() {}