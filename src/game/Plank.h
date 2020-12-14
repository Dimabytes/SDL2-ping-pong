#include "Texture.h"
#include <SDL.h>

#ifndef PLANK_H
#define PLANK_H
class Plank {
public:
    static const int width = 20, height = 70;
    static const int plankVel = 10;

    int posX, posY;
    int velY;

    SDL_Rect plankCollider;

    LTexture gPlankTexture;

    Plank(int x, int y);

    bool init();

    void handleEvent(SDL_Event &e, int p);

    void move();

    void render();
};

#endif