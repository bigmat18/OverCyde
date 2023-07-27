#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/geometric.hpp>

int main(void){

    Game game;
    bool success = game.Initialize();
    if (success) game.RunLoop();

    game.Shutdown();
    return 0;
}