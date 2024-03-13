#include "Renderer2D.h"
#include "Buffer.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "../Core/Types.h"
#include "../Core/Pch.h"
#include "../OpenGL/OpenGLShader.h"
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/fwd.hpp"
#include "glm/ext/matrix_transform.hpp"
#include <glm/gtx/string_cast.hpp>
#include <glm/glm.hpp>


namespace Engine {

    Renderer2D::Renderer2DData s_Data = Renderer2D::Renderer2DData();

    void Renderer2D::Inizialize() {
        s_Data.BaseShader = Ref<Shader>(Shader::Create("./assets/shaders/base_shader.vert", 
                                                       "./assets/shaders/base_shader.frag"));
        Renderer2D::InitTriangle();
        Renderer2D::InitSquare();
        Renderer2D::InitCircle();
    }

    void Renderer2D::Shutdown() {

    }
            
    void Renderer2D::DrawTriangle(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {
        Mat4f model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::scale(model, size);

        model = glm::rotate(model, glm::radians(degree.x), glm::normalize(Vec3f(1.0f, 0.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.y), glm::normalize(Vec3f(0.0f, 1.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.z), glm::normalize(Vec3f(0.0f, 0.0f, 1.0f)));

        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetMatrix4("u_Transform", model);
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetVec4("u_Color", color);
        s_Data.BaseShader->Bind();
        Renderer::Submit(s_Data.TriangleVertexArray); 
    }

    void Renderer2D::DrawSquare(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {

    }

    void Renderer2D::DrawCircle(Vec3f position, float radius, Vec4f color, Vec3f degree) {

    }
 
    void Renderer2D::DrawPolyhedron(ui32 sides, Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {
        // ENGINE_ASSERT(sides >= 5, "Polyhedron must have more than 4 sides");
        if(s_Data.PolyhedronVertexArray.count(sides) == 0) {
            InitPolyhedron(sides);
        }
        Mat4f model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::scale(model, size);

        model = glm::rotate(model, glm::radians(degree.x), glm::normalize(Vec3f(1.0f, 0.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.y), glm::normalize(Vec3f(0.0f, 1.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.z), glm::normalize(Vec3f(0.0f, 0.0f, 1.0f)));

        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetMatrix4("u_Transform", model);
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetVec4("u_Color", color);

        s_Data.BaseShader->Bind();
        Renderer::Submit(s_Data.PolyhedronVertexArray[sides]); 
    }

    void Renderer2D::InitTriangle() {
        std::vector<float> vertices = {
            0.0f, 1.0f, 0.0f,  
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f
        };
        std::vector<ui32> indices = { 0, 1, 2 };
        
        Ref<IndexBuffer> triangleIndices = Ref<IndexBuffer>(IndexBuffer::Create(&indices[0], indices.size() * sizeof(ui32)));
        Ref<VertexBuffer> triangleVertices = Ref<VertexBuffer>(VertexBuffer::Create(&vertices[0], vertices.size() * sizeof(float)));
        triangleVertices->SetLayout({
            { "a_Position", ShaderDataType::Float3 },
        });
        
        s_Data.TriangleVertexArray = Ref<VertexArray>(VertexArray::Create());
        s_Data.TriangleVertexArray->SetIndexBuffer(triangleIndices);
        s_Data.TriangleVertexArray->AddVertexBuffer(triangleVertices);
    }

    void Renderer2D::InitSquare() {
    
    }

    void Renderer2D::InitCircle() {

    }

    void Renderer2D::InitPolyhedron(ui32 sides) {
        std::vector<float> vertices;
        std::vector<ui32> indices;
        float interval = 360.0f / sides;
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        for(ui32 i = 0; i < sides; i++) {
            vertices.push_back(glm::cos(glm::radians(i * interval)));
            vertices.push_back(glm::sin(glm::radians(i * interval)));
            vertices.push_back(0.0f);

            indices.push_back(0);
            indices.push_back(i + 1);
            if(i + 2 <= sides) 
                indices.push_back(i + 2);
            else
                indices.push_back(1);
        }
       
        Ref<IndexBuffer> polyhedronIndices = Ref<IndexBuffer>(IndexBuffer::Create(&indices[0], indices.size() * sizeof(ui32)));
        Ref<VertexBuffer> polyhedronVertices = Ref<VertexBuffer>(VertexBuffer::Create(&vertices[0], vertices.size() * sizeof(float)));
        polyhedronVertices->SetLayout({
            { "a_Position", ShaderDataType::Float3 },
        });
         
        Ref<VertexArray> VS = Ref<VertexArray>(VertexArray::Create());
        VS->SetIndexBuffer(polyhedronIndices);
        VS->AddVertexBuffer(polyhedronVertices);
        s_Data.PolyhedronVertexArray.insert({sides, VS});
    }
}