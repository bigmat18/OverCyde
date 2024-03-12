#pragma once
#include "../Renderer/Texture.h"
#include "../Core/Pch.h"
#include <cstdint>

namespace Engine {
    class OpenGLTexture2D : public Texture2D {
        public:
            OpenGLTexture2D(std::string& path);
            virtual ~OpenGLTexture2D() = default;

            virtual uint32_t GetWindth() const override { return m_Width; };
            virtual uint32_t GetHeight() const override { return m_Height; };

            virtual void Bind(uint32_t slot) const override;

        private:
            uint32_t ID;
            std::string m_Path;
            uint32_t m_Width, m_Height;
    }; 
}
