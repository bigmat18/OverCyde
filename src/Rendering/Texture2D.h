#include <GL/glew.h>
#include <string>
#include "Texture.h"

#ifndef TEXTURE2D_H
#define TEXTURE2D_H

class Texture2D : private Texture {
    private:
        std::string filePath;

    public:
        Texture2D(const std::string& path);
        ~Texture2D();

        void Bind(GLuint slot = 0) override;
        void Unbind() override;
};

#endif