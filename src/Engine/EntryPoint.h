#pragma once
#include "Core/Log.h"
#include "Core/Application.h"

#ifdef ENGINE_PLATFORM

int main(void) {
    Engine::Log::Inizialize();

    LOG_CORE_INFO("Created application");
    auto app = Engine::Application::Create();

    LOG_CORE_INFO("App runnig");
    app->Run();

    LOG_CORE_INFO("Delete app");
    delete app;

    return 0;
}
#else
#error "Platform is not defined"
#endif