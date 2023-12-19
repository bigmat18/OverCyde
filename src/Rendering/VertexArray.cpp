#include "VertexArray.h"

VertexArray::VertexArray(){
    glGenVertexArrays(1, &this->mRendererID);
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1, &this->mRendererID);
}

void VertexArray::Bind() const {
    glBindVertexArray(this->mRendererID);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
    this->Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    GLuint offset = 0;
    for(unsigned int i = 0; i < elements.size(); ++i) {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, (size_t)layout.GetStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}
