#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game();
        ~Game();

        bool Initialize();
        void RunLoop();
        void Shutdown();
}; 

#endif