#pragma once
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace Core {
    class Log {

        public: 
            static void Inizialize();

            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define LOG_CORE_TRACE(...)     ::Core::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)      ::Core::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)      ::Core::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)     ::Core::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...)  ::Core::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LOG_TRACE(...)          ::Core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)           ::Core::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)           ::Core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)          ::Core::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)       ::Core::Log::GetClientLogger()->critical(__VA_ARGS__)