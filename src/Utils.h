#pragma once
#include "Pch.h"
#include "Log.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define DEBUG_BREAK __debugbreak()
#else
#define DEBUG_BREAK raise(SIGTRAP);
#endif

#define CORE_ASSERT(x, ...)                                       \
    {                                                             \
        if (!(x))                                                 \
        {                                                         \
            LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            DEBUG_BREAK;                                          \
        }                                                         \
    }

#define CLIENT_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            DEBUG_BREAK;                                            \
        }                                                           \
    }