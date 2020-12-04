#include "SDL_ttf.h"
#include "globals.h"
#include <string>
#include <sstream>

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup, TTF_Font *font) {
    int width = SCREEN_WIDTH, height = SCREEN_HEIGHT;
    SDL_Surface *surfaceGroup = TTF_RenderUTF8_Solid(font, text.c_str(), colorGroup);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surfaceGroup);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SDL_Rect rectGroup = {x, y, width, height};
    SDL_RenderCopy(gRenderer, texture, nullptr, &rectGroup);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surfaceGroup);
}

void renderText(const std::string& text, int x, int y, SDL_Color colorGroup) {
    renderText(text, x, y, colorGroup, font25);
}

void renderText(int text, int x, int y, SDL_Color colorGroup, TTF_Font *font) {
    std::stringstream strm;
    strm << text;
    renderText(strm.str(), x, y, colorGroup, font);
}

void renderText(int text, int x, int y, SDL_Color colorGroup) {
    renderText(text, x, y, colorGroup, font25);
}

#include "utils.h"
