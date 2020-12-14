#include "Plank.h"
#include <SDL.h>
#include "../globals.h"


Plank::Plank(int x, int y) {
    posX = x;
    posY = y;
    velY = 0;

    plankCollider.x = x;
    plankCollider.y = y;
    plankCollider.w = width;
    plankCollider.h = height;
}

bool Plank::init() {
    return gPlankTexture.loadFromFile("img/plank.bmp", gRenderer);
}

void Plank::handleEvent(SDL_Event &e, int p) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0 && p == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
                velY = velY - plankVel;
                break;
            case SDLK_s:
                velY = velY + plankVel;
                break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0 && p == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
                velY = velY + plankVel;
                break;
            case SDLK_s:
                velY = velY - plankVel;
                break;
        }
    } else if (e.type == SDL_KEYDOWN && e.key.repeat == 0 && p == 1) {
        switch (e.key.keysym.sym) {
            case SDLK_i:
                velY = velY - plankVel;
                break;
            case SDLK_k:
                velY = velY + plankVel;
                break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0 && p == 1) {
        switch (e.key.keysym.sym) {
            case SDLK_i:
                velY = velY + plankVel;
                break;
            case SDLK_k:
                velY = velY - plankVel;
                break;
        }
    }
}

void Plank::move() {
    posY = posY + velY;
    plankCollider.y = posY;
    if (posY <= 0 || posY + height >= SCREEN_HEIGHT) {
        posY = posY - velY;
    }
}

void Plank::render() {
    gPlankTexture.render(posX, posY, gRenderer);
}
