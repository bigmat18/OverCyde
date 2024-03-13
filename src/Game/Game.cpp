#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>
#include "GameLayer.h"

#define CUSTOM_COLOR 0xBF00FFFF

class Game : public Engine::Application {  
    friend class Engine::Application;

    private:
        Game(const Engine::WindowProps& props) : Engine::Application(props) {
            this->PushLayer(new GameLayer());
        }
};

Engine::Application* Engine::Application::Create() {
    WindowProps props = WindowProps();
    props.Title = "Game";
    props.Width = 720;
    props.Height = 720;
    return Engine::Application::SetInstance(new Game(props));
}

