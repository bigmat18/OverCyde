#pragma once
#include <chrono>
#include "../Types.h"

namespace Engine {
    class Clock {
        using NanoSec = std::chrono::nanoseconds;
        using HighResClock = std::chrono::high_resolution_clock;
        using TimePoint = std::chrono::time_point<HighResClock>;

        TimePoint mStartTime = HighResClock::now();
        TimePoint mCurrentTime = HighResClock::now();

        double mDeltaTime = 0;
        double mElapsedTime = 0;
        double mElapsedUnscaledTime = 0;

        bool isPause = false;
        float mTimeScale = 1;
        double mTimeFrame = 0;

        public:
            Clock() = default;
        
            Clock(float timeScale);

            void UpdateTime();

            void Reset() { mStartTime = mCurrentTime = HighResClock::now(); }

            void Pause() { isPause = true; }

            void Start() { isPause = false; }

            void SetTimeScale(float timeScale) { mTimeScale = timeScale; }

            double GetDeltaTime() const { return mDeltaTime; }

            double GetElapsedTime() const { return mElapsedTime; }

            double GetElapsedUnscaledTime() const { return mElapsedUnscaledTime; }

            ui64 Clock::GetTimeFrame() const { return mTimeFrame; }

            ui64 Clock::GetTimestamp() {
                ui64 unixTimestamp = std::chrono::seconds(std::time(nullptr)).count();
                return unixTimestamp;
            }
    };
}