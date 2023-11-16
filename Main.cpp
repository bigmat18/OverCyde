#include "src/Game.h"

int main(void) {
  Game game;
  bool success = game.Initialize();
  if (success)
    game.RunLoop();

  game.Shutdown();
  int a;
  return 0;
}
