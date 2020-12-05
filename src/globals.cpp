#include "globals.h"


int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

Profile profile1;
Profile profile2;

TTF_Font *font25;

SDL_Color CLR_WHITE = {255, 255, 255};

SDL_Texture *background;