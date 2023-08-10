#include "VertexBuffer.h"
#include "../Utils/debugging.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* data, GLuint size){
    glGenBuffers(1, &this->VBO);
    check_gl_errors(__LINE__, __FILE__);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    check_gl_errors(__LINE__, __FILE__);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    check_gl_errors(__LINE__, __FILE__);
}

VertexBuffer::~VertexBuffer(){ glDeleteBuffers(1, &this->VBO); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, this->VBO); }

void VertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }