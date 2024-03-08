#pragma once
#ifdef ENGINE_PLATFORM
#include "Core/Log.h"
#include "Core/Application.h"

int main(void) {
    Engine::Log::Inizialize();

    LOG_ENGINE_INFO("Created application");
    auto app = Engine::Application::Create();

    LOG_ENGINE_INFO("App runnig");
    app->Run();

    LOG_ENGINE_INFO("Delete app");
    delete app;

    return 0;
}
#else
#error "Platform is not defined"
#endif
