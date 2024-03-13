#pragma once
#include "../Core/Macro.h"
#include "../Core/Types.h"

namespace Engine {

    class Renderer {

        public:
            enum RendererType {
                None       = 0,
                Renderer2D = BIT(1),
                Renderer3D = BIT(2)
            }; 
 
            static void Inizialize(ui32 type = 0);
            static void Shutdown();

            static void Draw2DTriangle(Vec2f position = Vec2f(0.0f, 0.0f), 
                                       Vec2f size = Vec2f(1.0f, 1.0f), 
                                       Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                       float degree = 0.0f);

            static void Draw2DSquare(Vec2f position = Vec2f(0.0f, 0.0f), 
                                     Vec2f size = Vec2f(1.0f, 1.0f), 
                                     Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                     float degree = 0.0f);

            static void Draw2DCircle(float radius = 1.0f,
                                     Vec2f position = Vec2f(0.0f, 0.0f), 
                                     Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                     float degree = 0.0f);

            static void Draw2DPolyhedron(ui32 sides,
                                         Vec2f position = Vec2f(0.0f, 0.0f), 
                                         Vec2f size = Vec2f(1.0f, 1.0f), 
                                         Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                         float degree = 0.0f);
        private:
            static ui32 s_Type;
    };
}
