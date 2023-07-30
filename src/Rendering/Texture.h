#include <GL/glew.h>
#include <string>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    protected:
        GLuint rendererID;
        GLint width, height, BPP;
        unsigned char *localBuffer;

    public:
        Texture() : rendererID(0),
                    width(0),
                    height(0),
                    BPP(0),
                    localBuffer(nullptr) {};
        ~Texture() {};

        virtual void Bind(GLuint slot = 0) = 0;
        virtual void Unbind() = 0;

        int GetWidth() const { return this->width; }
        int GetHeight() const { return this->height; }
};

#endif