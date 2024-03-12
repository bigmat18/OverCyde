#pragma once

namespace Engine {
    class GraphicsContext {
        public:
            virtual ~GraphicsContext() = default;

            virtual void Initialize() = 0;
            virtual void SwapBuffers() = 0;

            static GraphicsContext* Create(void* window);
    };
}