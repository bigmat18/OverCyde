#ifndef GAME_OBJ_H
#define GAME_OBJ_H

class GameObj {
    public:
        GameObj();
        ~GameObj();

        class RendererComponent *renderer;
};

#endif