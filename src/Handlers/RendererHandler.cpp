#include "../Utils/debugging.h"
#include "../Utils/global.h"
#include "../Components/RendererComponent.h"
#include "ViewMatrix.h"
#include "RendererHandler.h"
#include <vector>

RendererHandler::RendererHandler(ViewMatrix *view) : view(view) {
    this->projection = glm::perspective(glm::radians(ZOOM),
                                        (float)(WIDTH) / (float)(HEIGHT),
                                        0.1f, 100.0f);
}

RendererHandler::~RendererHandler() {
    for (auto obj : this->objs)
        delete obj;
    delete this->view; 
}

GLFWwindow* RendererHandler::Initialize() {
    if (!glfwInit())
        return nullptr;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    this->window = glfwCreateWindow(WIDTH, HEIGHT, "OverCyde", NULL, NULL);
    if (!this->window) {
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(this->window);
    glewInit();
    printout_opengl_glsl_info();

    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return this->window;
}

void RendererHandler::Shutdown() { glfwTerminate(); }

void RendererHandler::Update() {
    glClearColor(DESTRUCT(BACKGROUND_COLOR));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto obj : this->objs){
        obj->Draw(this->window, this->projection, this->view->GetView());
    }
}

void RendererHandler::AddElement(RendererComponent *element) {
    this->objs.push_back(element);
}

void RendererHandler::RemoveElement(RendererComponent *element) {
    auto iter = std::find(this->objs.begin(), this->objs.end(), element);
    if (iter != this->objs.end()) {
        std::iter_swap(iter, this->objs.end() - 1);
        this->objs.pop_back();
    }
}