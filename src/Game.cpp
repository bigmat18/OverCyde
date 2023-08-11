#include "Game.h"
#include "Handlers/RendererHandler.h"
#include "Handlers/GameObjHandler.h"
#include "Components/RendererComponent.h"
#include "GameObj.h"
#include "Utils/debugging.h"
#include "Utils/global.h"
#include "Rendering/Surface.h"
#include "Rendering/Cube.h"
#include "Rendering/Shader.h"
#include "Rendering/Texture2D.h"
#include "Rendering/Texture3D.h"
#include "Rendering/Camera.h"
#include <glm/gtx/string_cast.hpp>

Camera *camera = new Camera(WIDTH, HEIGHT, 45, nullptr);

void MouseCallBackWrapper(GLFWwindow *window, double xpos, double ypos){
    if (camera)
        return camera->MouseCallBack(xpos, ypos);
}

void ScrollCallBackWrapper(GLFWwindow *window, double xoffset, double yoffset){
    if (camera)
        return camera->ScrollCallBack(yoffset);
}

Game::Game() : isRunning(true) 
{ 
    ViewMatrix *view = new ViewMatrix();
    this->gameObjHandler = new GameObjHandler();
    this->rendererHandler = new RendererHandler(view);
    camera->SetView(view);
}

bool Game::Initialize() {
    this->gameObjHandler->Initialize();
    this->window = this->rendererHandler->Initialize();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    this->LoadData();
    return this->window != nullptr;
}

void Game::RunLoop() {
    while(!glfwWindowShouldClose(this->window) && this->isRunning) {
        this->gameObjHandler->UpdateDeltaTime();
        this->ProcessInput(this->gameObjHandler->GetDeltaTime());

        glClearColor(DESTRUCT(BACKGROUND_COLOR));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(auto it = this->gameObjHandler->begin(), end = this->gameObjHandler->end(); it != end; ++it){
            const auto obj = *it;
            this->UpdateGame(obj);
            this->GenerateOutput(obj->GetRenderer());
        }

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}

void Game::ProcessInput(float deltaTime) {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(this->window, true);

    camera->ProcessInput(window, deltaTime);
    camera->UpdateView();
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
    std::string arr[] = {"sprites/texture_pietra_2_127_right.png",
                         "sprites/texture_pietra_2_127_left.png",
                         "sprites/texture_pietra_2_127_up.png",
                         "sprites/texture_pietra_2_127_up.png",
                         "sprites/texture_pietra_2_127_front.png",
                         "sprites/texture_pietra_2_127_front.png"};
    std::vector<std::string> paths(arr, arr + sizeof(arr) / sizeof(std::string));

    float side = 0.1f;
    Cube *cube = new Cube(side, true);
    Texture3D *tex3D = new Texture3D(paths);
    Shader *shader = new Shader("shaders/base.vert", "shaders/base.frag");

    for (int i = 0; i < 10; i++) {
        for(int j=0; j < 10; j++) {
            GameObj *obj = new GameObj();
            this->gameObjHandler->AddGameObj(obj);
            RendererComponent *renderer = new RendererComponent(obj, cube, shader);
            renderer->SetTexture(tex3D);
            obj->SetPosition(glm::vec3((side * 2 * i), 0.0f, (side * 2 * j)));
        }
    }
}

void Game::UnLoadData() {}