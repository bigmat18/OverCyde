#pragma once
#include "Event.h"
#include <Core/Types.h>
#include <sstream>

namespace Engine {
    class WindowCloseEvent : public Event {
        public:
            WindowCloseEvent() = default;

            EVENT_CLASS_TYPE(WindowClose);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };

    class WindowResizeEvent : public Event {
        public:
            WindowResizeEvent(ui32 width, ui32 height) 
                : m_Width(width), m_Height(height) {}; 

            EVENT_CLASS_TYPE(WindowResize);
            EVENT_CLASS_CATEGORY(EventCategoryApplication);

            ui32 GetWidth() const { return m_Width; }
            ui32 GetHeigth() const { return m_Height; }
            
            virtual std::string ToString() const override { 
                std::stringstream ss;
                ss << "WindowResizeEvent: " << this->m_Width << ", " << this->m_Height;
                return ss.str();
            } 
        private:
            ui32 m_Width, m_Height;
    };
}
