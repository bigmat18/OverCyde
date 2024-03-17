#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>
#include "GameLayer.h"

#define CUSTOM_COLOR 0x000000FF

class Game : public Engine::Application {  
    friend class Engine::Application;

    private:
        Game(const Engine::ApplicationProps& props) : Engine::Application(props) {
            this->PushLayer(new GameLayer());
        }
};

Engine::Application* Engine::Application::Create() {
    Engine::ApplicationProps props = Engine::ApplicationProps();
    props.WProps.Title = "Game";
    props.WProps.Width = 720;
    props.WProps.Height = 720;
    props.BGColor = Vec4f(HEX_COLOR(CUSTOM_COLOR));
    props.RType = Renderer::RendererType::Renderer2D;

    return Engine::Application::SetInstance(new Game(props));
}

