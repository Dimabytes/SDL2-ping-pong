#include "Profile.h"
#include "SDL.h"
#include "SDL_ttf.h"
#ifndef PINGPONG_GLOBALS_H
#define PINGPONG_GLOBALS_H

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern Profile profile1;
extern Profile profile2;

extern TTF_Font *font25;

extern SDL_Color CLR_WHITE;

extern SDL_Texture *background;


#endif //PINGPONG_GLOBALS_H
