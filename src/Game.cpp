#include "Game.h"
#include "Handlers/RendererHandler.h"
#include "Handlers/GameObjHandler.h"
#include "Components/RendererComponent.h"
#include "GameObj.h"
#include "Utils/debugging.h"
#include "Utils/global.h"
#include "Rendering/Cube.h"
#include "Rendering/Shader.h"
#include "Rendering/Texture.h"
#include "Rendering/Texture3D.h"

Game::Game() : isRunning(true) 
{ 
    this->gameObjHandler = new GameObjHandler();
    this->rendererHandler = new RendererHandler();
}

bool Game::Initialize() {
    this->gameObjHandler->Initialize();
    this->window = this->rendererHandler->Initialize();
    return this->window != nullptr;
}

void Game::RunLoop() {
    while(!glfwWindowShouldClose(this->window) && this->isRunning) {
        this->gameObjHandler->UpdateDeltaTime();
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
    this->gameObjHandler->Update(obj);
}

void Game::GenerateOutput(RendererComponent *obj) { 
    this->rendererHandler->Update(obj); 
}

void Game::Shutdown() {
    this->rendererHandler->Shutdown();
    this->gameObjHandler->Shutdown();
}

void Game::LoadData() {
    std::string arr[] = {"../sprites/grass_up.png",
                         "../sprites/grass_lateral.png",
                         "../sprites/grass_lateral.png",
                         "../sprites/grass_lateral.png",
                         "../sprites/grass_lateral.png",
                         "../sprites/grass_bottom.png" };

    std::vector<std::string> paths(arr, arr + sizeof(arr) / sizeof(std::string));
    Texture3D *tex = new Texture3D(paths);
    std::vector<Texture*> textures;
    textures.push_back(tex);

    GameObj *cube = new GameObj();
    RendererComponent *render = new RendererComponent(cube, textures, new Cube(1.0f), new Shader("../shaders/base.vert", "../shaders/base.vert"));
}

void Game::UnLoadData() {}