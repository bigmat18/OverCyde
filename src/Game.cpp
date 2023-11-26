#include "Game.h"
#include "Components/RendererComponent.h"
#include "GameObj.h"
#include "GameObjHandler.h"
#include "RendererHandler.h"
#include "Rendering/Camera.h"
#include "Rendering/Cube.h"
#include "Rendering/Shader.h"
#include "Rendering/Surface.h"
#include "Rendering/Texture2D.h"
#include "Rendering/Texture3D.h"
#include "Utils/debugging.h"
#include "Utils/global.h"
#include <glm/gtx/string_cast.hpp>

Camera *camera = new Camera(WIDTH, HEIGHT, 45, nullptr);

void MouseCallBackWrapper(GLFWwindow *window, double xpos, double ypos) {
  if (camera)
    return camera->MouseCallBack(xpos, ypos);
}

void ScrollCallBackWrapper(GLFWwindow *window, double xoffset, double yoffset) {
  if (camera)
    return camera->ScrollCallBack(yoffset);
}

Game::Game() : m_isRunning(true) {
  ViewMatrix *view = new ViewMatrix();
  this->m_gameObjHandler = new GameObjHandler();
  this->m_rendererHandler = new RendererHandler(view);
  camera->SetView(view);
}

Game::~Game() {
  delete this->m_gameObjHandler;
  delete this->m_rendererHandler;
}

bool Game::Initialize() {
  this->m_gameObjHandler->Initialize();
  this->m_window = this->m_rendererHandler->Initialize();
  glfwSetInputMode(this->m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  this->LoadData();

  return this->m_window != nullptr;
}

void Game::RunLoop() {
  while (!glfwWindowShouldClose(this->m_window) && this->m_isRunning) {
    this->m_gameObjHandler->UpdateDeltaTime();
    this->ProcessInput(this->m_gameObjHandler->GetDeltaTime());

    this->UpdateGame();
    this->GenerateOutput();

    glfwSwapBuffers(this->m_window);
    glfwPollEvents();
  }
}

void Game::ProcessInput(float deltaTime) {
  if (glfwGetKey(this->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(this->m_window, true);

  camera->ProcessInput(this->m_window, deltaTime);
  camera->UpdateView();
}

void Game::UpdateGame() { this->m_gameObjHandler->Update(); }

void Game::GenerateOutput() { this->m_rendererHandler->Update(); }

void Game::Shutdown() {
  this->m_rendererHandler->Shutdown();
  this->m_gameObjHandler->Shutdown();
}

void Game::LoadData() {
  std::string arr[] = {
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
  Surface *surface = new Surface(side * 4, side * 3.5);
  Texture2D *tex2D = new Texture2D("images/matt.png", 0);
  Texture3D *tex3D = new Texture3D(paths, 0);

  Shader *shader3D = new Shader("shaders/base_3d.vert", "shaders/base_3d.frag");
  Shader *shader2D = new Shader("shaders/base_2d.vert", "shaders/base_2d.frag");

  GameObj *matt = new GameObj();
  this->m_gameObjHandler->AddElement(matt);
  RendererComponent *rendererMatt =
      new RendererComponent(matt, surface, shader2D);
  rendererMatt->SetTexture(tex2D);
  matt->SetScale(glm::vec3(1.2f, 1.2f, 1.2f));

  this->m_rendererHandler->AddElement(rendererMatt);

  int nCubeInScreen = static_cast<int>(1.0f / side);
  int multiple = 1;

  for (int i = 0; i < nCubeInScreen * multiple; i++) {
    for (int j = 0; j < nCubeInScreen * multiple; j++) {
      GameObj *obj = new GameObj();
      RendererComponent *renderer =
          new RendererComponent(obj, cube3D, shader3D);

      this->m_gameObjHandler->AddElement(obj);
      this->m_rendererHandler->AddElement(renderer);

      renderer->SetTexture(tex3D);
      obj->SetPosition(glm::vec3((-1.0f * multiple) + side + (side * 2 * i),
                                 0.0f,
                                 (-1.0f * multiple) + side + (side * 2 * j)));
    }
  }
}

void Game::UnLoadData() {}
