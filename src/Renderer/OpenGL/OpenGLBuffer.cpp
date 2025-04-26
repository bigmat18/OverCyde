#include <GL/glew.h>
#include <Renderer/OpenGL/OpenGLBuffer.h>

namespace Engine {

    ///////////////////////////////////////////////////////////
    //////////////////// OpenGLVertexBuffer ///////////////////
    ///////////////////////////////////////////////////////////
    OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size) {
        glGenBuffers(1, &this->m_ID);
        glBindBuffer(GL_ARRAY_BUFFER, this->m_ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() { 
        glDeleteBuffers(1, &this->m_ID);
    }

    void OpenGLVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, this->m_ID);
    }

    void OpenGLVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    ///////////////////////////////////////////////////////////
    //////////////////// OpenGLIndexBuffer ////////////////////
    ///////////////////////////////////////////////////////////
    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t *indeces, uint32_t count) : m_Count(count) {
        glGenBuffers(1, &this->m_ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indeces, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() { 
        glDeleteBuffers(1, &this->m_ID);
    }

    void OpenGLIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ID);
    }

    void OpenGLIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}