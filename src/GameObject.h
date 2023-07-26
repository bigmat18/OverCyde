#include <glm/glm.hpp>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
    public:
        GameObject();
        ~GameObject();

    private:
        glm::vec3 position;
        class Game *game;
        class Quaternion rotation;
        float scale;
}

#endif