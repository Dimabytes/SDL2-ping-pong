#include <SDL.h>
#include "collision.h"

bool collisionLeftRight(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;


    leftA = a.x;
    rightA = a.x + a.w;

    leftB = b.x;
    rightB = b.x + b.w;

    if( rightA >= leftB || rightB >= leftA)
        return true;
    else
        return false;
}

bool collisionTopBottom(SDL_Rect a, SDL_Rect b)
{
    int topA, topB;
    int bottomA, bottomB;

    topA = a.y;
    bottomA = a.y + a.h;

    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA >= topB || topA >= bottomB )
        return true;
    else
        return false;
}

bool collisionDetector(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;

    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
        return false;

    if( topA >= bottomB )
        return false;

    if( rightA <= leftB )
        return false;

    if( leftA >= rightB )
        return false;

    return true;
}