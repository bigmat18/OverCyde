#pragma once
#include <string>
#include <cstdint>

#include <Core/Types.h>

#include "../Texture.h"

namespace Engine {
    class OpenGLTexture2D : public Texture2D {
        public:
            OpenGLTexture2D(const std::string& path);
            virtual ~OpenGLTexture2D() = default;

            virtual ui32 GetWindth() const override { return m_Width; };
            virtual ui32 GetHeight() const override { return m_Height; };

            virtual void Bind(ui32 slot) const override;

        private:
            ui32 ID;
            std::string m_Path;
            ui32 m_Width, m_Height;
    }; 
}
