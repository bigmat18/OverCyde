#pragma once
#ifdef ENGINE_PLATFORM
// #ifdef __APPLE__
// #define GL_SILENCE_DEPRECATION
// #endif

#include "Core/Log.h"
#include "Core/Application.h"

int main(void) {
    Engine::Log::Inizialize();
    Engine::Application *app;

    {    
        LOG_ENGINE_INFO("Created application");
        app = Engine::Application::Create();
    }

    {
        LOG_ENGINE_INFO("App runnig");
        app->Run();
    }

    {
        LOG_ENGINE_INFO("Delete app");
        delete app;
    }
    return 0;
}
#else
#error "Platform is not defined"
#endif
