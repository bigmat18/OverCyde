#pragma once
#include "../Core/Pch.h"

namespace Engine {
    class Texture {
        public:
            virtual ~Texture() = default;
            
            virtual uint32_t GetWindth() const = 0;
            virtual uint32_t GetHeight() const = 0;
            
            virtual void Bind(uint32_t slot) const = 0;
    };

    class Texture2D : public Texture {
        public:
            static Texture2D* Create(const std::string& path);
    };
};
