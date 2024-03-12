#pragma once
#include "../Events/Event.h"
#include "../Core/Macro.h"
#include "../Core/Types.h"

#define BACKGROUND_COLOR 0x000000FF

namespace Engine {

    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;
        Vec4f BackgroundColor;

        WindowProps(const std::string& title = "Engine", 
                    uint32_t width = 1280, 
                    uint32_t height = 720,
                    const Vec4f &backgroundColor = Vec4f(HEX_COLOR(BACKGROUND_COLOR)))
            : Title(title), 
              Width(width), 
              Height(height), 
              BackgroundColor(backgroundColor) {}
    };

    class Window {
        public:
            using EventCallbackFn = std::function<void(Event &)>;

            virtual ~Window() = default;
            
            virtual void OnUpdate() = 0;

            virtual float GetTime() const = 0;
            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;
            virtual const Vec4f GetBGColor() const = 0;    
        
            virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

            static Window *Create(const WindowProps &props);
    };
}
