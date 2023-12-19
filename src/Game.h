#include "SDL_video.h"
#include <GLFW/glfw3.h>
#include <SDL.h>

#ifndef GAME_H
#define GAME_H

class Game {

public:
    Game();
    ~Game();

    void Initialize();
    void RunLoop();
    void Shutdown();

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    void LoadData();
    void UnLoadData();

    SDL_Window *m_window;

    bool m_isRunning;
    class RendererSystem *m_renderer;
    class ECSystem *m_ecs;
};

#endif


