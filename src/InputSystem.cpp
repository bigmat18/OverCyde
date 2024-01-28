#include "InputSystem.h";

using namespace Input;

bool InputSystem::Inizialize() {
    this->m_state.Keyboard.m_currentState = SDL_GetKeyboardState(NULL);
    memset(this->m_state.Keyboard.m_prevState, 0, SDL_NUM_SCANCODES);
    return true;
}

void InputSystem::PrepareForUpdate() {
    memcpy(this->m_state.Keyboard.m_prevState, this->m_state.Keyboard.m_currentState, SDL_NUM_SCANCODES);
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode keyCode) const {
    if (this->m_prevState[keyCode] == 0) {
        if (this->m_currentState[keyCode] == 0)
            return ButtonState::ENone;
        else
            return ButtonState::EPressed;
    } else {
        if (this->m_currentState[keyCode] == 0)
            return ButtonState::EReleased;
        else
            return ButtonState::EHeld;
    }
}

