#include <glm/glm.hpp>

#ifndef GAME_OBJ_H
#define GAME_OBJ_H

class GameObj {

    public:
        GameObj(glm::vec3 position, 
                const class Game *game, 
                short int rotRadiant = 0, 
                glm::vec3 rotVec = (glm::vec3)(1.0f, 1.0f, 1.0f), 
                float scale = 1.0f) : position(position),
                                      game(game),
                                      rotRadiant(rotRadiant),
                                      rotVec(rotVec),
                                      scale(scale) {}

        ~GameObj(){};
        virtual void Draw();

    private:
        glm::vec3 position;
        const class Game *game;
        short int rotRadiant;
        glm::vec3 rotVec;
        float scale;
};

#endif