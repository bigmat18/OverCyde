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
        void UpdateGame(class GameObj*);
        void GenerateOutput(class RendererComponent *);

        void LoadData();
        void UnLoadData();

        void UpdateDeltaTime();

        GLFWwindow *window;
        
        GLfloat ticksCount;
        GLfloat deltaTime;
        
        GLboolean isRunning;
        class RendererHandler *rendererHandler;
        class GameObjHandler *gameObjHandler;
}; 

#endif