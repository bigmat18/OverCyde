#include "../Utils/debugging.h"
#include "../Utils/global.h"
#include "../Components/RendererComponent.h"
#include "RendererHandler.h"
#include <vector>

RendererHandler::RendererHandler() : Handler() {
    this->projection = glm::perspective(glm::radians(static_cast<float>(ZOOM)), 
                                                     static_cast<float>(HEIGHT) / static_cast<float>(WEIGHT),
                                                     0.1f, 100.0f);
    this->view = new ViewMatrix();
}

RendererHandler::~RendererHandler() { delete this->view; }

GLFWwindow* RendererHandler::Initialize() {
    if (!glfwInit())
        return nullptr;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    this->window = glfwCreateWindow(HEIGHT, WEIGHT, "OverCyde", NULL, NULL);
    if (!this->window) {
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(this->window);
    glewInit();
    printout_opengl_glsl_info();

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_DEPTH_TEST);

    return this->window;
}

void RendererHandler::Shutdown() { glfwTerminate(); }

void RendererHandler::Update(RendererComponent *obj) {
    obj->Draw(this->window, this->projection, this->view->GetView());
}