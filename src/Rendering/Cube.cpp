#include "Cube.h"
#include "VertexBuffer.h"
#include <iostream>

Cube::Cube(GLfloat side) : Shape(), side(side)
{ this->BuildShape(); }

void Cube::BuildShape() {
    GLfloat vertices[] = {
        -this->side, -this->side, -this->side, 0.0f, 0.0f,
        this->side, -this->side, -this->side, 1.0f, 0.0f,
        this->side, this->side, -this->side, 1.0f, 1.0f,
        this->side, this->side, -this->side, 1.0f, 1.0f,
        -this->side, this->side, -this->side, 0.0f, 1.0f,
        -this->side, -this->side, -this->side, 0.0f, 0.0f,

        -this->side, -this->side, this->side, 0.0f, 0.0f,
        this->side, -this->side, this->side, 1.0f, 0.0f,
        this->side, this->side, this->side, 1.0f, 1.0f,
        this->side, this->side, this->side, 1.0f, 1.0f,
        -this->side, this->side, this->side, 0.0f, 1.0f,
        -this->side, -this->side, this->side, 0.0f, 0.0f,

        -this->side, this->side, this->side, 1.0f, 0.0f,
        -this->side, this->side, -this->side, 1.0f, 1.0f,
        -this->side, -this->side, -this->side, 0.0f, 1.0f,
        -this->side, -this->side, -this->side, 0.0f, 1.0f,
        -this->side, -this->side, this->side, 0.0f, 0.0f,
        -this->side, this->side, this->side, 1.0f, 0.0f,

        this->side, this->side, this->side, 1.0f, 0.0f,
        this->side, this->side, -this->side, 1.0f, 1.0f,
        this->side, -this->side, -this->side, 0.0f, 1.0f,
        this->side, -this->side, -this->side, 0.0f, 1.0f,
        this->side, -this->side, this->side, 0.0f, 0.0f,
        this->side, this->side, this->side, 1.0f, 0.0f,

        -this->side, -this->side, -this->side, 0.0f, 1.0f,
        this->side, -this->side, -this->side, 1.0f, 1.0f,
        this->side, -this->side, this->side, 1.0f, 0.0f,
        this->side, -this->side, this->side, 1.0f, 0.0f,
        -this->side, -this->side, this->side, 0.0f, 0.0f,
        -this->side, -this->side, -this->side, 0.0f, 1.0f,

        -this->side, this->side, -this->side, 0.0f, 1.0f,
        this->side, this->side, -this->side, 1.0f, 1.0f,
        this->side, this->side, this->side, 1.0f, 0.0f,
        this->side, this->side, this->side, 1.0f, 0.0f,
        -this->side, this->side, this->side, 0.0f, 0.0f,
        -this->side, this->side, -this->side, 0.0f, 1.0f
    };
    GLuint indices[36];
    for(unsigned int i = 0; i<36; ++i) indices[i] = i;

    this->VBO = new VertexBuffer(vertices, 36 * 5 * sizeof(float));
    this->EBO = new IndexBuffer(indices, 36);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    this->VAO->AddBuffer(*this->VBO, layout);
}