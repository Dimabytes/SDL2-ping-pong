#include <string>
#include "Dot.h"
#include <SDL.h>
#include "../globals.h"

#ifndef DOT_H
#define DOT_H

Dot::Dot() {
    posX = SCREEN_WIDTH / 2;
    posY = 50;

    dotCollider.w = width;
    dotCollider.h = height;

    velX = -4;
    velY = 2;
}

bool Dot::init() {
    gDotTexture.loadFromFile("img/dot.png", gRenderer);
    gDotTexture.mWidth = width;
    gDotTexture.mHeight = width;
    return true;

}

void Dot::randomEvent(bool* isDot2) {
    double randNumber = ((double) rand() / (RAND_MAX));

    if(randNumber < 0.1){
        dotCollider.w = 50;
        dotCollider.h = 50;
        gDotTexture.mWidth = 50;
        gDotTexture.mHeight = 50;
    }

    if(randNumber >= 0.1 && randNumber < 0.2){
        dotCollider.w = 15;
        dotCollider.h = 15;
        gDotTexture.mWidth = 15;
        gDotTexture.mHeight = 15;
    }

    if(randNumber >= 0.2 && randNumber < 0.3){
        velX *= 2;
        velY *= 2;
    }

    if(randNumber >= 0.3 && randNumber < 0.4){
       *isDot2 = true;
    }
}

void Dot::move(SDL_Rect &p1, SDL_Rect &p2, bool* isDot2) {
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
        this->randomEvent(isDot2);
        velX = -1 * velX;
    } else if ((collisionDetector(dotCollider, p1) && collisionTopBottom(dotCollider, p1)) ||
               (collisionDetector(dotCollider, p2) && collisionTopBottom(dotCollider, p2))) {
        this->randomEvent(isDot2);
        velY = -1 * velY;
    }
    if(posX < 15){
        profile1.points -=1;
    }
    if(posX > SCREEN_WIDTH - 35){
        profile2.points -=1;
    }
    if (posX < 15 || posX > SCREEN_WIDTH - 35) {
        dotCollider.w = 30;
        dotCollider.h = 30;
        gDotTexture.mWidth = 30;
        gDotTexture.mHeight = 30;
       *isDot2 = false;

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