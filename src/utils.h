#include "SDL_ttf.h"
#ifndef PINGPONG_UTILS_H
#define PINGPONG_UTILS_H
#include <string>

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup, TTF_Font *font);

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup);

void renderText(int text, int x, int y, SDL_Color colorGroup, TTF_Font *font);

void renderText(int text, int x, int y, SDL_Color colorGroup);

void setBackground (const std::string &filename);

void drawBackground();

#endif //PINGPONG_UTILS_H
