#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game();
        ~Game() {};

        bool Initialize();
        void RunLoop();
        void Shutdown();

    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        void LoadData();
        void UnLoadData();

        GLFWwindow *window;
        uint32_t ticksCount;
        bool isRunning;
        class RendererHandler *rendererHandler;

}; 

#endif