#pragma once
#include <Core/Types.h>
#include <string>
namespace Engine {
    class Texture {
        public:
            virtual ~Texture() = default;
            
            virtual ui32 GetWindth() const = 0;
            virtual ui32 GetHeight() const = 0;
            
            virtual void Bind(ui32 slot) const = 0;
    };

    class Texture2D : public Texture {
        public:
            static Texture2D* Create(const std::string& path);
    };
};
