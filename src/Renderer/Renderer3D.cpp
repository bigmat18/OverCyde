#include <Renderer/Renderer3D.h>
#include <OpenGL/OpenGLShader.h>
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

    }

    void Renderer3D::BeginScene(float deltaTime) {
        s_Data.BaseShader->Bind();
        std::dynamic_pointer_cast<OpenGLShader>(s_Data.BaseShader)->SetMatrix4("u_ProjectionView", Mat4f(1.0f));
    }

    void Renderer3D::EndScene() {}

    void Renderer3D::DrawCube(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {

    }

    void Renderer3D::DrawPyramid(Vec3f position, Vec3f size, Vec4f color, Vec3f degree) {

    }

    void Renderer3D::InitCube() {

    }

    void Renderer3D::InitPyramid() {

    }
}