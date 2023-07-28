#include "Game.h"
#include "RendererHandler.h"
#include "Utils/debugging.h"
#include "Utils/global.h"

Game::Game() : isRunning(true) 
{ 
    this->rendererHandler = new RendererHandler();
}

bool Game::Initialize() {
    this->ticksCount = glfwGetTime();
    this->window = (GLFWwindow*)this->rendererHandler->Initialize();
    return this->window != nullptr;
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
    this->rendererHandler->Update(); 
}

void Game::Shutdown() {
    this->rendererHandler->Shutdown();
}

void Game::LoadData() {}

void Game::UnLoadData() {}