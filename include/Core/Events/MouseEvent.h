#pragma once
#include "Event.h"
#include "../Types.h"

namespace Engine {
    using MouseCode = ui16;
    
    class MouseMovedEvent : public Event {
        public:
            MouseMovedEvent(const float x, const float y)
                : m_MouseX(x), m_MouseY(y) {}

            float GetX() const { return m_MouseX; }
            float GetY() const { return m_MouseY; }

            EVENT_CLASS_TYPE(MouseMoved)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        private:
            float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event {
        public:
            MouseScrolledEvent(const float xOffset, const float yOffset)
                : m_XOffset(xOffset), m_YOffset(yOffset) {}

            float GetXOffset() const { return m_XOffset; }
            float GetYOffset() const { return m_YOffset; }


            EVENT_CLASS_TYPE(MouseScrolled)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        private:
            float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event {
        public:
            MouseCode GetMouseButton() const { return m_Button; }

            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
        protected:
            MouseButtonEvent(const MouseCode button)
                : m_Button(button) {}

            MouseCode m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
        public:
            MouseButtonPressedEvent(const MouseCode button)
                : MouseButtonEvent(button) {}

            EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
        public:
            MouseButtonReleasedEvent(const MouseCode button)
                : MouseButtonEvent(button) {}

            EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}