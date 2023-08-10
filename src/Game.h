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
        void ProcessInput(float deltaTime);
        void UpdateGame(class GameObj*);
        void GenerateOutput(class RendererComponent *);

        void LoadData();
        void UnLoadData();

        GLFWwindow *window;
        
        GLboolean isRunning;
        class RendererHandler *rendererHandler;
        class GameObjHandler *gameObjHandler;
}; 

#endif