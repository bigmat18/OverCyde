#include <GL/glew.h>
#include <string>
#include "Texture.h"

#ifndef TEXTURE2D_H
#define TEXTURE2D_H

class Texture2D : public Texture {
    private:
        std::string filePath;

    public:
        Texture2D(const std::string &path, GLuint slot);
        ~Texture2D();

        void Bind() override;
        void Unbind() override;

        std::string GetString() override { return this->filePath; }
};

#endif