#include <cstdio>
#include <string>
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>


class Dot {
public:
    static const int width = 30, height = 30;

    LTexture gDotTexture;

    int posX, posY;
    int velX, velY;

    SDL_Rect dotCollider;

    Dot();

    bool init();

    void move(SDL_Rect &p1, SDL_Rect &p2, bool* isDot2);

    void randomEvent(bool* isDot2);


    void render();

};