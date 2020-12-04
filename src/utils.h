#include "SDL_ttf.h"
#ifndef PINGPONG_UTILS_H
#define PINGPONG_UTILS_H

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup, TTF_Font *font);

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup);

void renderText(int text, int x, int y, SDL_Color colorGroup, TTF_Font *font);

void renderText(int text, int x, int y, SDL_Color colorGroup);

#endif //PINGPONG_UTILS_H
