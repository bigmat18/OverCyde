#pragma once
#include "../Core/Types.h"
#include "VertexArray.h"

namespace Engine {
    class Renderer2D {
        
        public:
            void Inizialize();
            void Shutdown();
            
            void DrawTriangle(Vec3f position, Vec3f size, Vec4f color, Vec3f rotation = Vec3f(0.0f, 0.0f, 0.0f));
            void DrawSquare(Vec3f position, Vec3f size, Vec4f color, Vec3f rotation = Vec3f(0.0f, 0.0f, 0.0f));
            void DrawCircle(Vec3f position, Vec4f size, Vec4f color, Vec3f rotation = Vec3f(0.0f, 0.0f, 0.0f));

            void DrawPolyhedron(int sides, Vec3f position, Vec4f size, Vec4f color, Vec3f rotation = Vec3f(0.0f, 0.0f, 0.0f));
            
        private:
            struct Renderer2DData {
                Scope<VertexArray> QuadVertexArray;
                Scope<VertexArray> TriangleVertexArray;
                Scope<VertexArray> CircleVertexArray;
            };

            static Renderer2DData m_Data;
    };
}
