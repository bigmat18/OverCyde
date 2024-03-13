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

/*****************************************************************************************************/
/*****************************************************************************************************/
/** Logging for engine (trace type) 
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_ENGINE_TRACE(...)             ::Engine::Log::GetEngineLogger()->trace(__VA_ARGS__)

/** Logging for engine (info type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_ENGINE_INFO(...)              ::Engine::Log::GetEngineLogger()->info(__VA_ARGS__)

/** Logging for engine (warn type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_ENGINE_WARN(...)              ::Engine::Log::GetEngineLogger()->warn(__VA_ARGS__)

/** Logging for engine (error type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_ENGINE_ERROR(...)             ::Engine::Log::GetEngineLogger()->error(__VA_ARGS__)

/** Logging for engine (critical type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_ENGINE_CRITICAL(...)          ::Engine::Log::GetEngineLogger()->critical(__VA_ARGS__)


/*****************************************************************************************************/
/*****************************************************************************************************/
/** Logging for client (trace type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_CLIENT_TRACE(...)             ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)

/** Logging for client (info type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_CLIENT_INFO(...)              ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)

/** Logging for client (warn type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_CLIENT_WARN(...)              ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)

/** Logging for client (error type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_CLIENT_ERROR(...)             ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)

/** Logging for client (critical type)
 * @param __VA_ARGS__ the string to print
 * */
#define LOG_CLIENT_CRITICAL(...)          ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)
