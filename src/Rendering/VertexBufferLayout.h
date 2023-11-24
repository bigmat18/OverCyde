#pragma once
#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
    GLuint type;
    GLuint count;
    GLubyte normalized;

    static GLuint GetSizeOfType(GLuint type){
        switch(type){
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        assert(false);
        return 0;
    }
}; 

class VertexBufferLayout {
    private:
        std::vector<VertexBufferElement> mElements;
        GLuint mStride;

    public:
        VertexBufferLayout() : mStride(0) {};

        template<typename T>
        void Push(unsigned int count) {}

        template<>
        void Push<float>(unsigned int count) { 
            this->mElements.push_back((VertexBufferElement){GL_FLOAT, count, GL_FALSE}); 
            this->mStride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
        }

        template <>
        void Push<unsigned int>(unsigned int count) {
            this->mElements.push_back((VertexBufferElement){GL_UNSIGNED_INT, count, GL_FALSE});
            this->mStride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
        }

        template<>
        void Push<unsigned char>(unsigned int count) { 
            this->mElements.push_back((VertexBufferElement){GL_UNSIGNED_BYTE, count, GL_TRUE});
            this->mStride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
        }

        inline const std::vector<VertexBufferElement> GetElements() const { return this->mElements; }
        inline GLuint GetStride() const { return this->mStride; }
};