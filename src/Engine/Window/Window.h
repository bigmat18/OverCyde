#pragma once
#include "../Core/Pch.h"
#include "../Events/Event.h"
 
namespace Core {

    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title = "Engine", 
                    uint32_t width = 1280, 
                    uint32_t height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class Window {
        public:
            using EventCallbackFn = std::function<void(Event &)>;

            virtual ~Window() {};
            
            virtual void OnUpdate() = 0;

            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;

            virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

            static Window *Create(const WindowProps &props);
    };
}