#include <Engine.h>

class Sandbox : public Core::Application {};

int main(void) {
    Core::Log::Inizialize();
    auto game = Sandbox::GetInstance();

    LOG_INFO("App running...");
    game->Run();
    delete game;

    return 0;
}