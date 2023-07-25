#include "Cube.h"
#include "VertexBuffer.h"
#include <iostream>

Cube::Cube(GLfloat side, const char *vertexPath, const char *fragmentPath, const Color *color, const bool texture)
    : Shape(vertexPath, fragmentPath), side(side), texture(texture), color(color)
{ this->BuildShape(); }

void Cube::BuildShape() {

    if(!this->texture) {
        GLfloat vertices[] = {
            -this->side, -this->side, this->side,
            this->side, -this->side, this->side,
            -this->side, this->side, this->side,
            this->side, this->side, this->side,
            -this->side, -this->side, -this->side,
            this->side, -this->side, -this->side,
            -this->side, this->side, -this->side,
            this->side, this->side, -this->side
        };

        GLuint indices[] = {
            0, 1, 2, 2, 1, 3,
            5, 4, 7, 7, 4, 6,
            4, 0, 6, 6, 0, 2,
            1, 5, 3, 3, 5, 7,
            2, 3, 6, 6, 3, 7,
            4, 5, 0, 0, 5, 1
        };

        this->VBO = new VertexBuffer(vertices, 8 * 3 * sizeof(float));
        this->EBO = new IndexBuffer(indices, 36);

        VertexBufferLayout layout;
        layout.Push<float>(3);
        this->VAO->AddBuffer(*this->VBO, layout);
    } else {
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
}

std::vector<Color> Cube::getColor(){
    std::vector<Color> colors;
    if(this->color != nullptr){
        int size = 8 ? this->texture : 36;
        for(unsigned int i = 0; i < size; i++)
            colors.push_back(*(this->color));

    } else if(!this->texture) {
        colors = {
            (Color){1.0f, 0.0f, 0.0f, 1.0f},
            (Color){0.0f, 1.0f, 0.0f, 1.0f},
            (Color){0.0f, 0.0f, 1.0f, 1.0f},
            (Color){1.0f, 0.0f, 1.0f, 1.0f},
            (Color){0.0f, 1.0f, 1.0f, 1.0f},
            (Color){1.0f, 1.0f, 0.0f, 1.0f},
            (Color){0.5f, 0.5f, 0.0f, 1.0f},
            (Color){0.0f, 0.5f, 0.5f, 1.0f}
        };
    } else {
        for(unsigned int i = 0; i < 36; i++)
            colors.push_back((Color){0.0f, 0.0f, 0.0f, 0.0f});
    }

    return colors;
}