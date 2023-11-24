#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game {
public:
  Game();
  ~Game();

  bool Initialize();
  void RunLoop();
  void Shutdown();

private:
  void ProcessInput(float deltaTime);
  void UpdateGame();
  void GenerateOutput();

  void LoadData();
  void UnLoadData();

  GLFWwindow *m_window;

  GLboolean m_isRunning;
  class RendererHandler *m_rendererHandler;
  class GameObjHandler *m_gameObjHandler;
};

#endif
