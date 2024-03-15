#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>

using namespace Engine;

class Game : public Application {  
    friend class Application;

    private: Game(ApplicationProps& props) : Application(props) {}
};

Application* Application::Create() {
    ApplicationProps props = ApplicationProps();

    props.WProps.Title = "ColziGame";
    props.WProps.Width = 360;
    props.WProps.Height = 360;
    props.BGColor = Vec4f(HEX_COLOR(0xBF00FFFF));

    return Application::SetInstance(new Game(props));
}