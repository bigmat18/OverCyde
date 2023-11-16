#include "IndexBuffer.h"
#include "Utils/debugging.h"
#include <GL/glew.h>

IndexBuffer::IndexBuffer(const GLuint* data, GLuint count) : mCount(count){
    glGenBuffers(1, &this->mRendererID);
    check_gl_errors(__LINE__, __FILE__);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->mRendererID);
    check_gl_errors(__LINE__, __FILE__);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
    check_gl_errors(__LINE__, __FILE__);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &this->mRendererID); }

void IndexBuffer::Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->mRendererID); }

void IndexBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }