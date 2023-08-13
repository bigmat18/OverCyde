#include <GL/glew.h>
#include <string>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    protected:
        GLuint rendererID;
        GLint width, height, BPP;
        unsigned char *localBuffer;
        GLuint slot;

    public:
        Texture(GLuint slot);
        ~Texture();

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        int GetWidth() const { return this->width; }
        int GetHeight() const { return this->height; }

        void SetFlipVerticallyOnLoad(bool value = true);
        void LoadImageBuffer(char const *string);
        void FreeImageBuffer();
};

#endif