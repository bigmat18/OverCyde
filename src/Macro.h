#pragma once
#include "Pch.h"
#include "Log.h"

#if _MSC_VER
    #include <intrin.h>
    #define debugbreak() __debugbreak()
#else
    #define debugbreak() __builtin_trap()
#endif

#define BIT(x) (1 << x)

#define HEX_COLOR(hex)             \
        ((hex) >> (3 * 8)) & 0xFF, \
        ((hex) >> (2 * 8)) & 0xFF, \
        ((hex) >> (1 * 8)) & 0xFF, \
        ((hex) >> (0 * 8)) & 0xFF  \

#define CORE_ASSERT(x, ...)                                       \
    {                                                             \
        if (!(x))                                                 \
        {                                                         \
            LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                         \
        }                                                         \
    }

#define CLIENT_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                           \
        }                                                           \
    }