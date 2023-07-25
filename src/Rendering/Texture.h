#include <GL/glew.h>
#include <string>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    private:
        GLuint rendererID;
        std::string filePath;
        unsigned char* localBuffer;
        GLint width, height, BPP;

    public:
        Texture(const std::string& path);
        ~Texture();

        void Bind(GLuint slot = 0) const;
        void Unbind() const;

        inline int GetWidth() const { return this->width; }
        inline int GetHeight() const { return this->height; }
};

#endif