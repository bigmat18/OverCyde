#include "GameObj.h"

#ifndef ACTOR_H
#define ACTOR_H

class Actor : GameObj {
    public:
        enum State {
            ACTIVE,
            PAUSED,
            DEAD
        };

        Actor(glm::vec3 position,
              const class Game *game,
              short int rotRadiant = 0,
              glm::vec3 rotVec = (glm::vec3)(1.0f, 1.0f, 1.0f),
              float scale = 1.0f,
              State state);

        ~Actor();

        void Update(float deltaTime);
        void UpdateComponents(float deltaTime);
        virtual void UpdateActor(float deltaTime);

    private:
        State state;
};

#endif