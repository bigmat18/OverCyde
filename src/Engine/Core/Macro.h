#pragma once
#include "Log.h"

#if _MSC_VER
    #include <intrin.h>
    #define debugbreak() __debugbreak()
#else
    #define debugbreak() __builtin_trap()
#endif

#if _MSC_VER
    #define ENGINE_API __declspec(dllexport)
#else
    #define ENGINE_API 
#endif

/**
 * Return 32 bit value with x value ad 1.
 * Example BIT(3) = 000...0300
 * @param x: unsigned integer
*/
#define BIT(x) (1 << x)

#define HEX_COLOR(hex)             \
        ((hex) >> (3 * 8)) & 0xFF, \
        ((hex) >> (2 * 8)) & 0xFF, \
        ((hex) >> (1 * 8)) & 0xFF, \
        ((hex) >> (0 * 8)) & 0xFF  \

#define ENGINE_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                           \
        }                                                           \
    }

#define CLIENT_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                           \
        }                                                           \
    }
