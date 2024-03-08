#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>

#define BACKGROUND_COLOR 0x0000FFFF

class Game : public Engine::Application {
    friend class Engine::Application;

    private:
        virtual void GenerateOutput() override {
            Engine::RenderCommand::SetClearColor({HEX_COLOR(BACKGROUND_COLOR)});
            Engine::RenderCommand::Clear();
        }

        Game(const Engine::WindowProps& props) : Application(props) {}
};

Engine::Application* Engine::Application::Create() {
    WindowProps props;
    props.Title = "Game";
    props.Width = 1280;
    props.Height = 720;
    return Engine::Application::SetInstance(new Game(props));
}