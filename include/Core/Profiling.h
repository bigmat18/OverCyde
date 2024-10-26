#pragma once
#include <chrono>
#include "Pch.h"
#include "../Layers/ImGuiLayer.h"

namespace Engine {

    class Profiling {
        public:
            struct ProfilingData {
                float Time;
                float AVGTime;
                float MaxTime;
                float MinTime;
            };

            static std::unordered_map<const char *, ProfilingData> GetData() { return s_ProfilingData; }

            static void AddData(const char* name, float time) {
                if(s_ProfilingData.count(name) == 0) {
                    s_ProfilingData.insert({name, {.Time = time, 
                                                   .AVGTime = time, 
                                                   .MaxTime = time, 
                                                   .MinTime = time}});
                } else {
                    s_ProfilingData[name] = {.Time = time,
                                             .AVGTime = (s_ProfilingData[name].AVGTime + time) / 2,
                                             .MaxTime = s_ProfilingData[name].MaxTime < time ? time : s_ProfilingData[name].MaxTime,
                                             .MinTime = s_ProfilingData[name].MinTime > time ? time : s_ProfilingData[name].MinTime};
                }
            } 

        private:
            static std::unordered_map<const char*, ProfilingData> s_ProfilingData;
    };

    template<typename Fn>
    class Timer {
        public:
            Timer(const char *name, Fn func) : m_Name(name), m_Func(func) { this->Reset(); }

            ~Timer() { this->Stop(); }

            void Reset() { this->m_Start = std::chrono::high_resolution_clock::now(); }

            void Stop() {
                float elapsed = this->Elapsed();
                this->m_Func(this->m_Name, elapsed);
            }

            float Elapsed() {
                return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - this->m_Start).count() * 0.001f * 0.001f * 0.001f;
            }

            float ElapsedMillis() {
                return this->Elapsed() * 1000.0f;
            }

        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
            const char* m_Name;
            Fn m_Func;
    };
}

#define PROFILING 1
#ifdef PROFILING
#define PROFILE_SCOPE(name)                                                       \
        Engine::Timer<std::function<void(const char*, float)>> timer##__LINE__(   \
            name, [&](const char* key, float time) {                             \
                Engine::Profiling::AddData(key, time);                           \
        })      
#else
#define PROFILE_SCOPE(name)
#endif
