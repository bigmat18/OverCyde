#include <GL/glew.h>

#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

class IndexBuffer {
    private:
        GLuint mRendererID;
        GLuint mCount;
    public:
        IndexBuffer(const GLuint* data, GLuint count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
    
        inline GLuint GetCount() const { return this->mCount; }
};

#endif