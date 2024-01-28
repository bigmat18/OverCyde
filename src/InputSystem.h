#include <SDL2/SDL.h>

#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

namespace Input {
enum ButtonState {
    ENone,
    EPressed,
    EReleased,
    EHeld
};

struct InputState {
    KeyboardState Keyboard;
};

struct KeyboardState {

    public:
        friend class InputSystem;

        bool GetKeyValue(SDL_Scancode keycode) const {
            return this->m_currentState[keycode] == 1;
        };

        ButtonState GetKeyState(SDL_Scancode keycode) const;

    private:
        const Uint8* m_currentState;
        Uint8 m_prevState[SDL_NUM_SCANCODES];
};

class InputSystem {

    public:
        bool Inizialize();
        void Shutdown();

        void PrepareForUpdate();
        void Update();

        const InputState& GetState() const { return this->m_state; };

    private:
        InputState m_state;

};
}

#endif
