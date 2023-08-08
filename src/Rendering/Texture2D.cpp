#include "Texture2D.h"
#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../Utils/stb_image.h"
#include <iostream>

Texture2D::Texture2D(const std::string &path) : Texture(), filePath(path)
{
    stbi_set_flip_vertically_on_load(true);
    this->localBuffer = stbi_load(this->filePath.c_str(), &this->width, &this->height, &this->BPP, 4);
    glGenTextures(1, &this->rendererID);
    glBindTexture(GL_TEXTURE_2D, this->rendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->localBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (this->localBuffer)
        stbi_image_free(this->localBuffer);
}

Texture2D::~Texture2D() { glDeleteTextures(1, &this->rendererID); }

void Texture2D::Bind(GLuint slot) {
    std::cout << "1" << std::endl;
    glActiveTexture(GL_TEXTURE0 + slot);
    std::cout << "2" << std::endl;
    glBindTexture(GL_TEXTURE_2D, this->rendererID);
    std::cout << "3" << std::endl;
}

void Texture2D::Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }