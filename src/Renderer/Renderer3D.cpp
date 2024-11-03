#include <Renderer/Renderer3D.h>
#include <OpenGL/OpenGLShader.h>
#include <Renderer/RenderCommand.h>
#include <Core/Types.h>

namespace Engine {
    Renderer3D::Renderer3DData Renderer3D::s_Data = Renderer3D::Renderer3DData();
    bool Renderer3D::s_IsCameraActive;


    void Renderer3D::Initialize(ui32 width, ui32 heigth, bool activeCamera) {
        s_IsCameraActive = activeCamera;
        s_Data.BaseShader = Ref<Shader>(Shader::Create("shaders/base_shader.vert", 
                                                       "shaders/base_shader.frag"));

        Renderer3D::InitCube();
        Renderer3D::InitPyramid();
    }

    void Renderer3D::Shutdown() {
        s_Data.BaseShader.reset();
        s_Data.CubeVertexArray.reset();
        s_Data.PyramidVertexArray.reset();
    }

    void Renderer3D::BeginScene(float deltaTime) {
        s_Data.BaseShader->Bind();
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetMatrix4("u_ProjectionView", Mat4f(1.0f));
    }

    void Renderer3D::EndScene() {}

    void Renderer3D::DrawCube(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {
        Renderer3D::Draw(s_Data.CubeVertexArray, position, size, color, degree);
    }

    void Renderer3D::DrawPyramid(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {

    }

    void Renderer3D::Draw(Ref<VertexArray> VA, Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {
        Mat4f model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::scale(model, size);

        model = glm::rotate(model, glm::radians(degree.x), glm::normalize(Vec3f(1.0f, 0.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.y), glm::normalize(Vec3f(0.0f, 1.0f, 0.0f)));
        model = glm::rotate(model, glm::radians(degree.z), glm::normalize(Vec3f(0.0f, 0.0f, 1.0f)));

        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetMatrix4("u_Transform", model);
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetVec4("u_Color", glm::normalize(color));
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetBool("u_ActiveTex", false);
        RenderCommand::DrawIndex(VA); 
    }

    void Renderer3D::InitCube() {
        std::vector<float> vertices = {
            -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
            0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
            0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f,  0.5f, -0.5f, 0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f, 0.0f, 0.0f
        };

        std::vector<ui32> indices = {
            0, 1, 2,
            2, 3, 0,
            1, 5, 6,
            6, 2, 1,
            5, 4, 7,
            7, 6, 5,
            4, 0, 3,
            3, 7, 4,
            3, 2, 6,
            6, 7, 3,
            4, 5, 1,
            1, 0, 4
        };

        Ref<IndexBuffer> cubeIndices = Ref<IndexBuffer>(IndexBuffer::Create(&indices[0], indices.size()));
        Ref<VertexBuffer> cubeVertices = Ref<VertexBuffer>(VertexBuffer::Create(&vertices[0], vertices.size() * sizeof(float)));
        cubeVertices->SetLayout({
            { "a_Position", ShaderDataType::Float3 },
            { "a_TexCoord", ShaderDataType::Float2 },
        });
        s_Data.CubeVertexArray = Ref<VertexArray>(VertexArray::Create());
        s_Data.CubeVertexArray->SetIndexBuffer(cubeIndices);
        s_Data.CubeVertexArray->SetVertexBuffer(cubeVertices); 
    }

    void Renderer3D::InitPyramid() {

    }
}