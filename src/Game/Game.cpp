#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>

using namespace Engine;

class Game : public Application {  
    friend class Application;

    private: Game() : Application() {}
};

Application* Application::Create() {
    return Application::SetInstance(new Game());
}