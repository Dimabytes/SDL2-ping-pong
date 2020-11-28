#include <cstdio>
#include <string>
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>


LTexture::LTexture() {
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {
    free();
}

bool LTexture::loadFromFile(const std::string &path, SDL_Renderer *gRenderer) {
    free();
    SDL_Texture *newTexture = nullptr;

    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("FAILED TO LOAD SURFACE\n");
    } else {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("FAILED TO CREATE texture\n");
        } else {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }

    mTexture = newTexture;
    return mTexture != nullptr;
}

void LTexture::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(int x, int y, SDL_Renderer *gRenderer) {
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    SDL_RenderCopy(gRenderer, mTexture, nullptr, &renderQuad);
}
