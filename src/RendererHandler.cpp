#include "RendererHandler.h"
#include "Utils/debugging.h"
#include "Utils/global.h"

RendererHandler::RendererHandler(){
    this->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    this->view = ViewMatrix();
}

RendererHandler::~RendererHandler() {}

bool RendererHandler::Initialize(GLFWwindow *window) {
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(HEIGHT, WEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glewInit();
    printout_opengl_glsl_info();

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_DEPTH_TEST);

    return true;
}

void RendererHandler::Shutdown(GLFWwindow *window) {
    glfwTerminate();
}

void RendererHandler::Update(GLFWwindow *window) {
    glClearColor(DESTRUCT(BACKGROUND_COLOR));
    glClear(GL_COLOR_BUFFER_BIT);

    // for(auto obj : this->objs )
    //     obj->Draw(deltaTime, this->projection, this->view);

    glfwSwapBuffers(window);
}

void RendererHandler::AddElement(RendererObj *obj) {
    this->objs.emplace_back(obj);
}

void RendererHandler::RemoveElement(RendererObj *obj) {
    auto iter = std::find(this->objs.begin(), this->objs.end(), obj);
    if (iter != this->objs.end()){
        std::iter_swap(iter, this->objs.end() - 1);
        this->objs.pop_back();
    }
}