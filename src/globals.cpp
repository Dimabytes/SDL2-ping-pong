#include "globals.h"


int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

Profile profile1;
Profile profile2;

TTF_Font *font25;
TTF_Font *font15;

SDL_Color CLR_WHITE = {255, 255, 255};
SDL_Color CLR_BLACK = {0, 0, 0};
SDL_Color CLR_ORANGE = {204, 51, 0};
SDL_Color CLR_GREEN = {51, 204, 51};

SDL_Texture *background;