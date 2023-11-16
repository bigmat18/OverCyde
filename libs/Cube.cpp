#include "Cube.h"
#include "VertexBuffer.h"
#include "Utils/debugging.h"
#include <iostream>

Cube::Cube(GLfloat side, const bool is3D) : Shape(), side(side), is3D(is3D)
{ this->BuildShape(); }

void Cube::BuildShape() {
    if (this->is3D) this->BuildShape3D();
    else this->BuildShape2D();
}

void Cube::BuildShape2D() {
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
        -this->side, this->side, -this->side, 0.0f, 1.0f};

    GLuint indices[36];
    for (unsigned int i = 0; i < 36; ++i)
            indices[i] = i;

    this->VBO = new VertexBuffer(vertices, 36 * 5 * sizeof(float));
    this->EBO = new IndexBuffer(indices, 36);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    this->VAO->AddBuffer(*this->VBO, layout);
}

void Cube::BuildShape3D() {
    GLfloat vertices[] = {
        -this->side, this->side, -this->side,
        -this->side, -this->side, -this->side,
        this->side, -this->side, -this->side,
        this->side, -this->side, -this->side,
        this->side, this->side, -this->side,
        -this->side, this->side, -this->side,

        -this->side, -this->side, this->side,
        -this->side, -this->side, -this->side,
        -this->side, this->side, -this->side,
        -this->side, this->side, -this->side,
        -this->side, this->side, this->side,
        -this->side, -this->side, this->side,

        this->side, -this->side, -this->side,
        this->side, -this->side, this->side,
        this->side, this->side, this->side,
        this->side, this->side, this->side,
        this->side, this->side, -this->side,
        this->side, -this->side, -this->side,

        -this->side, -this->side, this->side,
        -this->side, this->side, this->side,
        this->side, this->side, this->side,
        this->side, this->side, this->side,
        this->side, -this->side, this->side,
        -this->side, -this->side, this->side,

        -this->side, this->side, -this->side,
        this->side, this->side, -this->side,
        this->side, this->side, this->side,
        this->side, this->side, this->side,
        -this->side, this->side, this->side,
        -this->side, this->side, -this->side,

        -this->side, -this->side, -this->side,
        -this->side, -this->side, this->side,
        this->side, -this->side, -this->side,
        this->side, -this->side, -this->side,
        -this->side, -this->side, this->side,
        this->side, -this->side, this->side};

    GLuint indices[36];
    for (unsigned int i = 0; i < 36; ++i)
            indices[i] = i;

    this->VBO = new VertexBuffer(vertices, 36 * 3 * sizeof(float));
    this->EBO = new IndexBuffer(indices, 36);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    this->VAO->AddBuffer(*this->VBO, layout);
}
