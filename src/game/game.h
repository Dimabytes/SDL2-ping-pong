#include "Dot.h"
#include "Plank.h"

#include "SDL.h"

#ifndef PINGPONG_GAME_H
#define PINGPONG_GAME_H

class Game {
    Dot dot;
    Plank plank1 = Plank(20, 480 / 2 - 35);
    Plank plank2 = Plank(640 - 40, 480 / 2 - 35);

    SDL_Renderer * gRenderer;

public:
    Game(SDL_Renderer * renderer);

    void handleEvent(SDL_Event * e, bool * isScene);
};

#endif //PINGPONG_GAME_H
