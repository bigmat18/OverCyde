#include "Cube.h"
#include "VertexBuffer.h"
#include "../Utils/debugging.h"
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
    check_gl_errors(__LINE__, __FILE__);
    this->EBO = new IndexBuffer(indices, 36);
    check_gl_errors(__LINE__, __FILE__);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    this->VAO->AddBuffer(*this->VBO, layout);
    check_gl_errors(__LINE__, __FILE__);
}