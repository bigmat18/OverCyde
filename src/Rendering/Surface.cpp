#include "Surface.h"
#include "VertexBuffer.h"
#include "../Utils/debugging.h"
#include <iostream>

Surface::Surface(GLfloat side) : Shape(), side(side)
{ this->BuildShape(); }

void Surface::BuildShape() {
    GLfloat vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
    };

    GLuint indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    this->VBO = new VertexBuffer(vertices, 4 * 5 * sizeof(float));
    check_gl_errors(__LINE__, __FILE__);
    this->EBO = new IndexBuffer(indices, 6);
    check_gl_errors(__LINE__, __FILE__);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    this->VAO->AddBuffer(*this->VBO, layout);
    check_gl_errors(__LINE__, __FILE__);
}