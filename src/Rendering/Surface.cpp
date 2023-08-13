#include "Surface.h"
#include "VertexBuffer.h"
#include "../Utils/debugging.h"
#include <iostream>

Surface::Surface(GLfloat height, GLfloat width) : Shape(), height(height), width(width)
{ this->BuildShape(); }

void Surface::BuildShape() {
    GLfloat vertices[] = {
        // positions                                // texture coords
        this->width / 2.0f, this->height / 2.0f,    0.0f, 1.0f, 1.0f,        // top right
        this->width / 2.0f, -this->height / 2.0f,   0.0f, 1.0f, 0.0f,        // bottom right
        -this->width / 2.0f, -this->height / 2.0f,  0.0f, 0.0f, 0.0f,        // bottom left
        -this->width / 2.0f, this->height / 2.0f,   0.0f, 0.0f, 1.0f         // top left
    };

    GLuint indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    this->VBO = new VertexBuffer(vertices, 4 * 5 * sizeof(float));
    this->EBO = new IndexBuffer(indices, 6);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    this->VAO->AddBuffer(*this->VBO, layout);
}