#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>
#include "GameLayer.h"

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
    props.WProps.Width = 1080;
    props.WProps.Height = 720;
    props.ActiveCamera = true;
    props.ActiveDebugging = true;
    props.RType = Renderer::RendererType::Renderer2D;

    return new Game(props);
}