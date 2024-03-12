#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>
#include "GameLayer.h"

#define CUSTOM_COLOR 0xBF00FFFF

class Game : public Engine::Application {  
    friend class Engine::Application;

    private:
        Game(const Engine::WindowProps& props) : Application(props) {
            this->PushLayer(new GameLayer());
        }
};

Engine::Application* Engine::Application::Create() {
    WindowProps props = WindowProps();
    props.Title = "Game";
    props.Width = 1280;
    props.Height = 720;
    props.BackgroundColor = Vec4f(HEX_COLOR(CUSTOM_COLOR));
    return Engine::Application::SetInstance(new Game(props));
}

