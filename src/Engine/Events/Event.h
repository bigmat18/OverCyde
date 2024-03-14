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
    /**
     * The event types in the engine created by the window.
     * None
     * For Application: WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved
     * For Keyboard:    KeyPressed, KeyReleased, KeyTyped
     * For Mouse:       MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased
    */
    enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
        MouseMoved, MouseScrolled,
		MouseButtonPressed, MouseButtonReleased 
    };

    /**
     * The event categorys in the engine create by the window. 
     * It's rapresentd with BIT() macro (see Macro.h)
     * None
     * EventCategoryApplication
     * EventCategoryInput
     * EventCategoryKeyboard
     * EventCategoryMouse
     * EventCategoryMouseButton
     */
    enum EventCategory {
        None                        = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
    };

    /**
     * This class is the base class for all events
    */
    class Event {
        friend class EventDispatcher;

        public: 
            /**
             * Get the type of event 
             * @return EventType enum
            */
            virtual EventType GetEventType() const = 0;

            /**
             * Get the name of event (the name of class)
            */
            virtual const char* GetName() const = 0;

            /**
             * Get the category flags, this is a 32 bit int with x value in x position
             * of bit number. Example: 000...00x0 is BIT(1) flags
            */
            virtual int GetCategoryFlags() const = 0;

            virtual ~Event() = default;

            /**
             * Check if category is in the category of the event.
            */
            inline bool IsInCategory(EventCategory category) {
                return this->GetCategoryFlags() & category;
            }

            /**
             * This method check if event is handled by a eventdistpacher. When
             * a event is handled it don't be handle another time
            */
            inline bool IsHandled() const { return this->m_Handled; }

            /**
             * Print the event (base is GetName())
            */
            virtual std::string ToString() const { return GetName(); }

        protected:
            bool m_Handled = false;
    };

    /**
     * This class is used to dispatch event to a funcion to handle it.
    */
    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

        public:
            EventDispatcher(Event &event) : m_Event(event) {};
            ~EventDispatcher() {};

            /**
             * This method execute the dispatch. 
             * @param fun is the function where event is dispatched to send it a function you should
             * use the BIND_FUN() macro or std::bind
             * @return return true if event was dispatch to fun
            */
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
