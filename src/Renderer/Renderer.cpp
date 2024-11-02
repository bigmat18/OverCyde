#include <Renderer/Renderer.h>
#include <Renderer/Renderer2D.h>
#include <OpenGL/OpenGLShader.h>
#include <Renderer/RenderCommand.h>
#include <Events/ApplicationEvent.h>

namespace Engine {
    ui32 Renderer::s_Type = 0;

    void Renderer::Inizialize(ui32 width, ui32 heigth, ui32 type, bool activeCamera) {
        s_Type = type;
        if (s_Type & Renderer::RendererType::Renderer2D)
            Renderer2D::Inizialize(width, heigth, activeCamera);
    }

    void Renderer::Shutdown() {
        Renderer2D::Shutdown();
    }

    void Renderer::BeginScene(float deltaTime) {
        if (s_Type & Renderer::RendererType::Renderer2D)
            Renderer2D::BeginScene(deltaTime);
    }

    void Renderer::EndScene() {
        if (s_Type & Renderer::RendererType::Renderer2D)
            Renderer2D::EndScene();
    }
    
    void Renderer::Draw2DTriangle(Vec2f position, Vec2f size, Vec4f color, float degree) {
        ENGINE_ASSERT(s_Type & Renderer2D, "You must init Renderer2D");
        Renderer2D::DrawTriangle(Vec3f(position, 0.0f), Vec3f(size, 0.0f), color, Vec3f(0.0f, 0.0f, degree));
    }

    void Renderer::Draw2DSquare(Vec2f position, Vec2f size, Vec4f color, float degree) {
        ENGINE_ASSERT(s_Type & Renderer2D, "You must init Renderer2D");
        Renderer2D::DrawSquare(Vec3f(position, 0.0f), Vec3f(size, 0.0f), color, Vec3f(0.0f, 0.0f, degree));
    }

    void Renderer::Draw2DCircle(float radius, Vec2f position, Vec4f color, float degree) {
        ENGINE_ASSERT(s_Type & Renderer2D, "You must init Renderer2D");
        Renderer2D::DrawCircle(radius, Vec3f(position, 0.0f), color, Vec3f(0.0f, 0.0f, degree));
    }

    void Renderer::Draw2DPolyhedron(ui32 sides, Vec2f position, Vec2f size, Vec4f color, float degree) {
        ENGINE_ASSERT(s_Type & Renderer2D, "You must init Renderer2D");
        Renderer2D::DrawPolyhedron(sides, Vec3f(position, 0.0f), Vec3f(size, 1.0f), color, Vec3f(0.0f, 0.0f, degree));
    }

    void Renderer::OnWindowResize(WindowResizeEvent &e) {
        // RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeigth());
        if (s_Type & Renderer::RendererType::Renderer2D)
            Renderer2D::OnWindowResize(e);
    }
}
