#pragma once
#include "spdlog/spdlog.h"

namespace Engine {
    class Log {

        public: 
            static void Inizialize();

            inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        private:
            static std::shared_ptr<spdlog::logger> s_EngineLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define LOG_ENGINE_TRACE(...)             ::Engine::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_ENGINE_INFO(...)              ::Engine::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_ENGINE_WARN(...)              ::Engine::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_ENGINE_ERROR(...)             ::Engine::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_ENGINE_CRITICAL(...)          ::Engine::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define LOG_CLIENT_TRACE(...)             ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_CLIENT_INFO(...)              ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_CLIENT_WARN(...)              ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_CLIENT_ERROR(...)             ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CLIENT_CRITICAL(...)          ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)
