#include <Renderer/OpenGL/OpenGLTexture.h>
#include <Core/Utils.h>
#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Engine {
    OpenGLTexture2D::OpenGLTexture2D(const std::string& path) : m_Path(path) {
        int channels, width, height;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* buffer = stbi_load(path.c_str(), &width, &height, &channels, 4);
        ENGINE_ASSERT(buffer, "Failed to load image - " + path);
        
        this->m_Height = height;
        this->m_Width = width;
        glGenTextures(1, &this->ID);
        glBindTexture(GL_TEXTURE_2D, this->ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->m_Width, this->m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
        glBindTexture(GL_TEXTURE_2D, 0);
        
        stbi_image_free(buffer);
        LOG_CLIENT_INFO("active texture {0} on {1}", path, this->ID);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, this->ID);
    }

}
