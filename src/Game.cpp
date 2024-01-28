#include "Game.h"
#include "RendererSystem.h"
#include "InputSystem.h"
#include "ECSystem.h"

#include "Components/RendererComponent.h"
#include "Entity.h"

#include "Rendering/Surface.h"
#include "Rendering/Cube.h"
#include "Rendering/Shader.h"
#include "Rendering/Texture2D.h"
#include "Rendering/Texture3D.h"
#include "Rendering/Camera.h"

#include <glm/gtx/string_cast.hpp>
#include <SDL.h>


Game::Game() : m_isRunning(true) { 
    ViewMatrix *view = new ViewMatrix();
    this->m_ecs = new ECSystem();
    this->m_renderer = new RendererSystem(view);
    this->m_input = new Input::InputSystem();
}

Game::~Game() {
    delete this->m_ecs;
    delete this->m_renderer;
    delete this->m_input;
}

void Game::Initialize() {
    this->m_ecs->Initialize();
    this->m_renderer->Initialize();
    this->LoadData();
}

void Game::RunLoop() {
    while(this->m_isRunning) {
        this->m_ecs->UpdateDeltaTime();
        this->ProcessInput();
        this->UpdateGame();
        this->GenerateOutput();
    }
}

void Game::ProcessInput() { 
    this->m_input->PrepareForUpdate();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            this->m_isRunning = false;
            break;
        case SDL_MOUSEWHEEL:
            // mInputSystem->ProcessEvent(event);
            break;
        default:
            break;
        }
    }
    this->m_input->Update();
    this->m_ecs->ProcessInput(this->m_input->GetState());
}

void Game::UpdateGame() { this->m_ecs->Update(); }

void Game::GenerateOutput() { this->m_renderer->Update(); }

void Game::Shutdown() {
    this->m_renderer->Shutdown();
    this->m_ecs->Shutdown();
    this->UnLoadData();
}

void Game::LoadData() {
    /*std::string arr[] = {
        "images/texture_pietra_2_127_right.png", // Right
        "images/texture_pietra_2_127_left.png",  // Left
        "images/texture_pietra_2_127_up.png",    // Top
        "images/black.png",                      // Bottom
        "images/texture_pietra_2_127_front.png", // Front
        "images/black.png"                       // Back
    };
    std::vector<std::string> paths(arr, arr + sizeof(arr) / sizeof(std::string));


    float side = 0.05f;
    Cube *cube3D = new Cube(side, true);
    Surface *surface = new Surface(side*4, side*3.5);
    Texture2D *tex2D = new Texture2D("images/matt.png", 0);
    Texture3D *tex3D = new Texture3D(paths, 0);

    Shader *shader3D = new Shader("shaders/base_3d.vert", "shaders/base_3d.frag");
    Shader *shader2D= new Shader("shaders/base_2d.vert", "shaders/base_2d.frag");
    

    Entity *matt = new Entity();
    this->m_ecs->AddElement(matt);
    RendererComponent *rendererMatt = new RendererComponent(matt, surface, shader2D);
    rendererMatt->SetTexture(tex2D);
    matt->SetScale(glm::vec3(1.2f, 1.2f, 1.2f));

    this->m_renderer->AddElement(rendererMatt);

    int nCubeInScreen = static_cast<int>(1.0f / side);
    int multiple = 1;

    for (int i = 0; i < nCubeInScreen * multiple; i++) {
        for(int j=0; j < nCubeInScreen * multiple; j++) {
            Entity *obj = new Entity();
            RendererComponent *renderer = new RendererComponent(obj, cube3D, shader3D);

            this->m_ecs->AddElement(obj);
            this->m_renderer->AddElement(renderer);

            renderer->SetTexture(tex3D);
            obj->SetPosition(glm::vec3((-1.0f * multiple) + side + (side * 2 * i), 0.0f, (-1.0f * multiple) + side + (side * 2 * j)));
        }
    }*/
}

void Game::UnLoadData() {}
