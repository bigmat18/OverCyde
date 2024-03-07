#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>

#define BACKGROUND_COLOR 0x0000FFFF

class Game : public Core::Application {
    friend class Core::Application;

    private:
        virtual void GenerateOutput() override {
            Core::RenderCommand::SetClearColor({HEX_COLOR(BACKGROUND_COLOR)});
            Core::RenderCommand::Clear();
        }

        Game(const Core::WindowProps& props) : Application(props) {}
};

Core::Application* Core::Application::Create() {
    WindowProps props;
    props.Title = "Game";
    props.Width = 1280;
    props.Height = 720;
    return Core::Application::SetInstance(new Game(props));
}