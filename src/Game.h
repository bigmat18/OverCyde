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

        void AddActor(class Actor *actor);
        void RemoveActor(class Actor *actor);

    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        GLFWwindow *window;
        uint32_t ticksCount;
        bool isRunning;

        std::vector<class Actor*> actors;
}; 

#endif