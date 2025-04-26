#include <Core/Time/Clock.h>

namespace Engine {

    Clock::Clock(float timeScale) : mTimeScale(timeScale) {}
    
    void Clock::UpdateTime() {
        mTimeFrame++;
        mDeltaTime = 0.0;

        if (!isPause) {
          TimePoint newTime = HighResClock::now();

          NanoSec delta =
              std::chrono::duration_cast<NanoSec>(newTime - mCurrentTime);
          NanoSec elapse =
              std::chrono::duration_cast<NanoSec>(newTime - mStartTime);
      
          mCurrentTime = newTime;
          mDeltaTime = delta.count() * 1e-9 * mTimeScale;
          mElapsedTime += mDeltaTime;
          mElapsedUnscaledTime = elapse.count() * 1e-9;
        }
    }
}
