#pragma once
#include "../Events/Event.h"
#include "../Core/Macro.h"
#include "../Core/Types.h"

namespace Engine {

    /**
     * The props of window
    */
    struct WindowProps {
        /** The title of window (defualt = "Default Window")*/
        std::string Title;

        /** The width of window (default = 1280)*/
        uint32_t Width;

        /** The height of windowc (default = 720)*/
        uint32_t Height;

        /** Constructor for WindowProps with default: Title = "Default Window", Width = 1280, Height = 720 */
        WindowProps(const std::string &title = "Default Window",
                    uint32_t width = 1280,
                    uint32_t height = 720)
            : Title(title),
              Width(width),
              Height(height) {}
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
