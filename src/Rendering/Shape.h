#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <glm/glm.hpp>

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    protected:
        VertexArray *VAO;
        VertexBuffer *VBO;
        IndexBuffer *EBO;

    public:
        Shape(){ this->VAO = new VertexArray(); };

        ~Shape() {
            delete this->VAO;
            delete this->VBO;
            delete this->EBO;
        }

        virtual void BuildShape() {};

        void Draw() const {
            this->VAO->Bind();
            this->VBO->Bind();
            this->EBO->Bind();
            glDrawElements(GL_TRIANGLES, this->EBO->GetCount(), GL_UNSIGNED_INT, 0);
        }
};

#endif