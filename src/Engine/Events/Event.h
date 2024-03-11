#pragma once
#include "../Core/Pch.h"
#include "../Core/Log.h"
#include "../Core/Macro.h"

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType GetStaticType() { return EventType::type; }                \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

namespace Engine {
    enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
        MouseMoved, MouseScrolled,
		MouseButtonPressed, MouseButtonReleased 
    };

    enum EventCategory {
        None                        = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
    };

    class Event {
        friend class EventDispatcher;

        public: 
            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual int GetCategoryFlags() const = 0;

            virtual ~Event() = default;

            inline bool IsInCategory(EventCategory category) {
                return this->GetCategoryFlags() & category;
            }

            inline bool IsHandled() const { return this->m_Handled; }

            virtual std::string ToString() const { return GetName(); }

        protected:
            bool m_Handled = false;
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

        public:
            EventDispatcher(Event &event) : m_Event(event) {};
            ~EventDispatcher() {};

            template<typename T>
            bool Dispatch(EventFn<T> fun){
                if(this->m_Event.GetEventType() == T::GetStaticType()){
                    this->m_Event.m_Handled = fun(*(T*)&this->m_Event);
                    LOG_ENGINE_INFO("Dispatch event {0}", this->m_Event.ToString());
                    return true;
                }
                return false;
            }

        private:
            Event& m_Event;
    };
} 
