#pragma once

namespace Core {
    class GraphicsContext {
        public:
            virtual ~GraphicsContext() = default;

            virtual void Initialize() = 0;
            virtual void SwapBuffers() = 0;
    };
}