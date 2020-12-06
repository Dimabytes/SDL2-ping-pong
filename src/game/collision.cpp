#include <SDL.h>
#include "collision.h"

bool collisionLeftRight(SDL_Rect a, SDL_Rect b){
    return a.x + a.w >= b.x || b.x + b.w >= a.x;
}

bool collisionTopBottom(SDL_Rect a, SDL_Rect b){
    return a.y + a.h >= b.y || a.y >= b.y + b.h;
}

bool collisionDetector(SDL_Rect a, SDL_Rect b){
    return a.y + a.h > b.y && a.y < b.y + b.h && a.x + a.w > b.x && a.x <  b.x + b.w;
}