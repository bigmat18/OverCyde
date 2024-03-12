#pragma once
#include "../Core/Types.h"
#include "Shader.h"
#include "VertexArray.h"

namespace Engine {
    class Renderer2D {
        
        public:
            static void Inizialize();
            static void Shutdown();
           
            static void DrawTriangle(Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), 
                                     Vec3f size = Vec3f(1.0f, 1.0f, 1.0f), 
                                     Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                     Vec3f degree = Vec3f(0.0f, 0.0f, 0.0f));
     
            static void DrawSquare(Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), 
                                   Vec3f size = Vec3f(1.0f, 1.0f, 1.0f), 
                                   Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                   Vec3f degree = Vec3f(0.0f, 0.0f, 0.0f));

            static void DrawCircle(Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), 
                                   float radius = 1.0f, 
                                   Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                   Vec3f degree = Vec3f(0.0f, 0.0f, 0.0f));

            static void DrawPolyhedron(int sides, 
                                       Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), 
                                       Vec3f size = Vec3f(1.0f, 1.0f, 1.0f), 
                                       Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                       Vec3f degree = Vec3f(0.0f, 0.0f, 0.0f)); 

            struct Renderer2DData {
                Ref<VertexArray> QuadVertexArray;
                Ref<VertexArray> TriangleVertexArray;
                Ref<VertexArray> CircleVertexArray;

                Ref<Shader> BaseShader;
            };
            
        private:
            static void InitTriangle();
            static void InitSquare();
            static void InitCircle();


            static Renderer2DData m_Data;
    };
}
