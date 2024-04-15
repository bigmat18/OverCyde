#pragma once
#include <chrono>
#include "../Layers/ImGuiLayer.h"

namespace Engine {

    class Profiling {
        public:
            struct ProfilingData
            {
                const char *Name;
                float Time;
            };

            static std::vector<ProfilingData> GetData() { return s_ProfilingData ;}
            static void AddData(ProfilingData data) { s_ProfilingData.push_back(data); } 
            static void ClearData() { s_ProfilingData.clear(); }

        private:
            static std::vector<ProfilingData> s_ProfilingData;
    };

    template<typename Fn>
    class Timer {
        public:
            Timer(const char *name, Fn func) : m_Name(name), m_Func(func) { this->Reset(); }

            ~Timer() { this->Stop(); }

            void Reset() { this->m_Start = std::chrono::high_resolution_clock::now(); }

            void Stop() {
                float elapsed = this->Elapsed();
                this->m_Func({this->m_Name, elapsed});
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

#define PROFILE_SCOPE(name) Engine::Timer<std::function<void(Profiling::ProfilingData)>> timer##__LINE__( \
        name, [&](Engine::Profiling::ProfilingData profileResult) {                                       \
            Engine::Profiling::AddData(profileResult);                                                    \
        })                                                                                                \
