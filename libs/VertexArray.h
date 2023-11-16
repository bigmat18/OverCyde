#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <GL/glew.h>

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

class VertexArray{
    private:
        GLuint mRendererID;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout& layout);
        void Bind() const;
        void Unbind() const;
};

#endif