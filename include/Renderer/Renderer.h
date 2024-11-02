#pragma once
#include "Core/Macro.h"
#include "Core/Types.h"
#include "Events/ApplicationEvent.h"

namespace Engine {

    class Renderer {

        public:
            /**
             * The renderer types to init 
            */
            enum RendererType {
                None       = 0,
                Renderer2D = BIT(0),
                Renderer3D = BIT(1)
            }; 
 
            static void Inizialize(ui32 width, ui32 heigth, ui32 type = 0, bool activeCamera = false);
            static void Shutdown();

            static void BeginScene(float deltaTime);
            static void EndScene(); 

            /**
             * Draw triangle in 2D space.
             * @param position a Vec2f with x, y value normalized (default = 0.0f, 0.0f)
             * @param size a vec2f with the width and height sizes normalized (default = 1.0f, 1.0f)
             * @param color a Vec4f with r,g,b,a color normalized (default = 1.0f, 1.0f, 1.0f, 1.0f white color)
             * @param degree the degree to rotate shape (default = 0.0f)
             */
            static void Draw2DTriangle(Vec2f position = Vec2f(0.0f, 0.0f), 
                                       Vec2f size = Vec2f(1.0f, 1.0f), 
                                       Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                       float degree = 0.0f);

            /**
             * Draw square in 2D space.
             * @param position a Vec2f with x, y value normalized (default = 0.0f, 0.0f)
             * @param size a vec2f with the width and height sizes normalized (default = 1.0f, 1.0f)
             * @param color a Vec4f with r,g,b,a color normalized (default = 1.0f, 1.0f, 1.0f, 1.0f white color)
             * @param degree the degree to rotate shape (default = 0.0f)
             */
            static void Draw2DSquare(Vec2f position = Vec2f(0.0f, 0.0f), 
                                     Vec2f size = Vec2f(1.0f, 1.0f), 
                                     Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                     float degree = 0.0f);

            /**
             * Draw circle in 2D space.
             * @param radius the radius of circle (default = 1.0f)
             * @param position a Vec2f with x, y value normalized (default = 0.0f, 0.0f)
             * @param color a Vec4f with r,g,b,a color normalized (default = 1.0f, 1.0f, 1.0f, 1.0f white color)
             * @param degree the degree to rotate shape (default = 0.0f)
             */
            static void Draw2DCircle(float radius = 1.0f,
                                     Vec2f position = Vec2f(0.0f, 0.0f), 
                                     Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                     float degree = 0.0f);

            /**
             * Draw polyhedron in 2D space.
             * @param sides the sides of polyhedron (it must be greater than or equal to 5)
             * @param position a Vec2f with x, y value normalized (default = 0.0f, 0.0f)
             * @param size a vec2f with the width and height sizes normalized (default = 1.0f, 1.0f)
             * @param color a Vec4f with r,g,b,a color normalized (default = 1.0f, 1.0f, 1.0f, 1.0f white color)
             * @param degree the degree to rotate shape (default = 0.0f)
             */
            static void Draw2DPolyhedron(ui32 sides,
                                         Vec2f position = Vec2f(0.0f, 0.0f), 
                                         Vec2f size = Vec2f(1.0f, 1.0f), 
                                         Vec4f color = Vec4f(1.0f, 1.0f, 1.0f, 1.0f), 
                                         float degree = 0.0f);

            
            static void OnWindowResize(WindowResizeEvent &e);

        private:
            static ui32 s_Type;
    };
}
