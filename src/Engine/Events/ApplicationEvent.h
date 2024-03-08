#pragma once
#include "Event.h"

namespace Engine {
    class WindowCloseEvent : public Event {
        public:
            WindowCloseEvent() = default;

            EVENT_CLASS_TYPE(WindowClose);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };

    class WindowResizeEvent : public Event {
        public:
            WindowResizeEvent(uint32_t width, uint32_t height) 
                : m_Width(width), m_Height(height) {}; 

            EVENT_CLASS_TYPE(WindowResize);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);

        private:
            uint32_t m_Width, m_Height;
    };
}