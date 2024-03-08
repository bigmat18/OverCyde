#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define CORE_NAME "CORE"
#define CLIENT_NAME "CLIENT"
#define FORMATTING "%^[%T] %n: %v%$"

namespace Engine {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Inizialize() {
        spdlog::set_pattern(FORMATTING);
        s_CoreLogger = spdlog::stdout_color_mt(CORE_NAME);
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt(CLIENT_NAME);
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}