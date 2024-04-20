#pragma once
#include "../Core/Types.h"
#include "Renderer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "CameraController.h"
#include <map>

namespace Engine {
    class Renderer2D {
        friend class Renderer;     

        protected:
            static void Inizialize();
            static void Shutdown();

            static void BeginScene(float deltaTime);
            static void EndScene();
           
            static void DrawTriangle(Vec3f position, Vec3f size, Vec4f color, Vec3f degree);
     
            static void DrawSquare(Vec3f position, Vec3f size, Vec4f color, Vec3f degree);

            static void DrawCircle(float radius, Vec3f position, Vec4f color, Vec3f degree);

            static void DrawPolyhedron(ui32 sides, Vec3f position, Vec3f size, Vec4f color, Vec3f degree); 

        public:
            struct Renderer2DData {
                Ref<VertexArray> SquareVertexArray;
                Ref<VertexArray> TriangleVertexArray;
                Ref<VertexArray> CircleVertexArray;

                Ref<Shader> BaseShader;
                std::map<ui32, Ref<VertexArray>> PolyhedronVertexArray;
            };
            
        private:

            static void InitTriangle();
            static void InitSquare();
            static void InitCircle();
            static void InitPolyhedron(ui32 sides);

            static void Draw(Ref<VertexArray> VA, Vec3f position, Vec3f size, Vec4f color, Vec3f degree);

            static Renderer2DData s_Data;
            static Camera2DController s_CameraController;
    };
}
