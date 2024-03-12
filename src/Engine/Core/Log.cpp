#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define ENGINE_NAME "ENGINE"
#define CLIENT_NAME "CLIENT"
#define FORMATTING "%^[%T] %n: %v%$"

namespace Engine {
    std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Inizialize() {
        spdlog::set_pattern(FORMATTING);
        s_EngineLogger = spdlog::stdout_color_mt(ENGINE_NAME);
        s_EngineLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt(CLIENT_NAME);
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
