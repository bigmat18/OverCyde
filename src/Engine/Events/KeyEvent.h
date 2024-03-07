#pragma once
#include "Event.h"
#include "KeyCode.h"

namespace Core {
    class KeyEvent : public Event {
        public:
            KeyCode GetKeyCode() const { return this->m_Keycode; };

            EVENT_CLASS_CATEGORY(EventCategoryKeyboard)

        protected:
            KeyEvent(const KeyCode keycode)
                : m_Keycode(keycode){};

            KeyCode m_Keycode;
    };

    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
                : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

            bool IsRepeat() const { return m_IsRepeat; }

            EVENT_CLASS_TYPE(KeyPressed)
        private:
            bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(const KeyCode keycode)
                : KeyEvent(keycode) {}

            EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent {
        public:
            KeyTypedEvent(const KeyCode keycode)
                : KeyEvent(keycode) {}

            EVENT_CLASS_TYPE(KeyTyped)
    };
}