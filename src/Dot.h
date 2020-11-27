#include <cstdio>
#include <string>
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>


class Dot {
public:
    static const int width = 20, height = 20;

    LTexture gDotTexture;

    int posX, posY;
    int velX, velY;

    SDL_Rect dotCollider;

    Dot();

    bool init(SDL_Renderer * gRenderer);

    void move(SDL_Rect &p1, SDL_Rect &p2, int screenWidth, int screenHeight);

    void render(SDL_Renderer* gRenderer);

};