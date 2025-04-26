#pragma once
#include "VertexArray.h"
#include "Renderer.h"
#include "Shader.h"
#include <Core/Types.h>

namespace Engine {

    class Renderer3D {
        friend class Renderer;

        protected:
            static void Initialize(ui32 width, ui32 heigth, bool activeCamera);
            static void Shutdown();

            static void BeginScene(float deltaTime);
            static void EndScene();

            static void DrawCube(Vec3f position, Vec3f size, Vec4f color, Vec3f degree);

            static void Draw(Ref<VertexArray> VA, Vec3f position, Vec3f size, Vec4f color, Vec3f degree);

        public:
            struct Renderer3DData {
                Ref<VertexArray> CubeVertexArray;
                Ref<VertexArray> PyramidVertexArray;

                Ref<Shader> BaseShader;
            };

        private:
            static void InitCube();

            static Renderer3DData s_Data;
            static bool s_IsCameraActive;
    };

}