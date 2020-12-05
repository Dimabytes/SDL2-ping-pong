#include <string>
#include "Dot.h"
#include <SDL.h>
#include "../globals.h"

#ifndef DOT_H
#define DOT_H

Dot::Dot() {
    posX = 50;
    posY = 50;

    dotCollider.w = width;
    dotCollider.h = height;

    velX = -4;
    velY = 2;
}

bool Dot::init() {
    gDotTexture.loadFromFile("img/dot.png", gRenderer);
    gDotTexture.mWidth = 30;
    gDotTexture.mHeight = 30;
    return true;

}

void Dot::move(SDL_Rect &p1, SDL_Rect &p2) {
    posY = posY + velY;
    dotCollider.y = posY;
    posX = posX + velX;
    dotCollider.x = posX;

    if (posX < 0 || (posX + width) > SCREEN_WIDTH) {
        velX = -1 * velX;
    }
    else if (posY < 0 || (posY + height) > SCREEN_HEIGHT) {
        velY = -1 * velY;
    }

    if ((collisionDetector(dotCollider, p1) && collisionLeftRight(dotCollider, p1)) ||
        (collisionDetector(dotCollider, p2) && collisionLeftRight(dotCollider, p2))) {
        std::cout << velX << "," << velY << "\n";
        velX = -1 * velX;
        std::cout << velX << "," << velY << "\n";
    } else if ((collisionDetector(dotCollider, p1) && collisionTopBottom(dotCollider, p1)) ||
               (collisionDetector(dotCollider, p2) && collisionTopBottom(dotCollider, p2))) {
        std::cout << velX << "," << velY << "\n";
        velY = -1 * velY;
        std::cout << velX << "," << velY << "\n";
    }
    if(posX < 15){
        profile1.points -=1;
    }
    if(posX > SCREEN_WIDTH - 35){
        profile2.points -=1;
    }
    if (posX < 15 || posX > SCREEN_WIDTH - 35) {
        posX = SCREEN_WIDTH / 2;
        posY = rand() % SCREEN_HEIGHT;
        int z = rand() % 4;
        switch (z) {
            case 0:
                velX = -5;
                velY = -3;
                break;
            case 1:
                velX = 6;
                velY = -4;
                break;
            case 2:
                velX = -7;
                velY = 3;
                break;
            default:
                velX = 4;
                velY = 7;
                break;
        }
    }
}


void Dot::render() {
    gDotTexture.render(posX, posY, gRenderer);
}

#endif