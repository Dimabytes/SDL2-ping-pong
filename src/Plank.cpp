#include "iostream"
#include "Plank.h"
#include <SDL.h>


Plank::Plank(int x, int y) {
    posX = x;
    posY = y;
    velX = 0;
    velY = 0;

    plankCollider.x = x;
    plankCollider.y = y;
    plankCollider.w = width;
    plankCollider.h = height;
}

bool Plank::init(SDL_Renderer *gRenderer) {
    return gPlankTexture.loadFromFile("img/plank.bmp", gRenderer);
}

void Plank::handleEvent(SDL_Event &e, int p) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0 && p == 0) {
        std::cout << "3";
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

void Plank::move(int screenHeight) {
    posY = posY + velY;
    plankCollider.y = posY;
    if (posY <= 0 || posY + height >= screenHeight) {
        posY = posY - velY;
    }
}

void Plank::render(SDL_Renderer *gRenderer) {
    gPlankTexture.render(posX, posY, gRenderer);
}
