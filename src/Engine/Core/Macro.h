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
 * Example BIT(3) = 000...3000
 * @param x: unsigned integer
*/
#define BIT(x) (1 << x)

/**
 * Execute the std::bin for x. Example: BIND_FUN(myFunction)
 * @param x the function to bind
*/
#define BIND_FUN(x) std::bind(&x, this, std::placeholders::_1)

/**
 * Get a unsigned integer at 32 bit (hex format) and convert it to x, y, z, w
 * @param hex: ess. 0x01FF0200
 * @return 1, 15, 2, 0
*/
#define HEX_COLOR(hex)             \
        ((hex) >> (3 * 8)) & 0xFF, \
        ((hex) >> (2 * 8)) & 0xFF, \
        ((hex) >> (1 * 8)) & 0xFF, \
        ((hex) >> (0 * 8)) & 0xFF  \

/**
 * Engine assert to interrupt exe when x is false
 * @param x: a condition that must be true
 * @param __VA_ARGS__: the output string if x is false
*/
#define ENGINE_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                           \
        }                                                           \
    }

/**
 * Client assert to interrupt exe when x is false
 * @param x: a condition that must be true
 * @param __VA_ARGS__: the output string if x is false
 */
#define CLIENT_ASSERT(x, ...)                                       \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            debugbreak();                                           \
        }                                                           \
    }
