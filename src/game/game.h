#include "Dot.h"
#include "Plank.h"
#include "../backButton.h"

#include "SDL.h"

#ifndef PINGPONG_GAME_H
#define PINGPONG_GAME_H

class Game {
    Dot dot;
    Dot dot2;

    bool isDot2 = false;
    Plank plank1 = Plank(20, 480 / 2 - 35);
    Plank plank2 = Plank(640 - 40, 480 / 2 - 35);
    BackButton backButton;


public:
    Game();
    void restart();
    void handleEvent(SDL_Event e, bool * isScene);
};

#endif //PINGPONG_GAME_H
