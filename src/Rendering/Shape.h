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
        Shader *shader;

    public:
        Shape(const char *vertexPath, const char *fragmentPath){
            this->shader = new Shader(vertexPath, fragmentPath);
            this->VAO = new VertexArray();
        };

        ~Shape() {
            delete this->VAO;
            delete this->VBO;
            delete this->EBO;
            delete this->shader;
        }

        virtual void BuildShape() {};

        void Draw() const {
            this->shader->use();
            this->VAO->Bind();
            this->VBO->Bind();
            this->EBO->Bind();
            glDrawElements(GL_TRIANGLES, this->EBO->GetCount(), GL_UNSIGNED_INT, 0);
        }

        template <typename T>
        void setShaderUniform(T data, const char* name) {}

        template <>
        void setShaderUniform<glm::mat4>(glm::mat4 data, const char* name) { this->shader->setMatrix4(name, data); }

        template <>
        void setShaderUniform<glm::vec3>(glm::vec3 data, const char *name) { this->shader->setVec3(name, data); }
};

#endif