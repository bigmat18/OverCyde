#include "Game.h"
#include "Utils/debugging.h"
#include "Utils/global.h"

Game::Game() : window(nullptr),
               isRunning(true) {}

bool Game::Initialize() {
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    this->window = glfwCreateWindow(HEIGHT, WEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!this->window) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(this->window);
    glewInit();
    printout_opengl_glsl_info();

    GLFWvidmode return_struct;

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_DEPTH_TEST);
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

void Game::ProcessInput() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(this->window, true);
}

void Game::UpdateGame() {

}

void Game::GenerateOutput() {
    glClearColor(DESTRUCT(BACKGROUND_COLOR));
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Game::Shutdown() {
    glfwTerminate();
}