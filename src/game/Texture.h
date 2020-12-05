#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "collision.h"
#include <SDL.h>
#include <SDL_image.h>

#ifndef TEXTURE_H
#define TEXTURE_H
class LTexture {
public:
    LTexture();

    ~LTexture();

    bool loadFromFile(const std::string &path, SDL_Renderer *gRenderer);

    void free();

    void render(int x, int y, SDL_Renderer *gRenderer);
    int mWidth;
    int mHeight;
private:
    SDL_Texture *mTexture;

};
#endif