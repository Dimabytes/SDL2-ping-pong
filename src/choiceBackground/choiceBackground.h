#include "SDL.h"
#include "../globals.h"

#ifndef PINGPONG_CHOICEBACKGROUND_H
#define PINGPONG_CHOICEBACKGROUND_H


void choiceBackground (SDL_Event * e, bool * isScene);

class ChoiceBackground {
    int x = 0, y = 0;
    bool isMenu = false;
    static const int NUMMENU = 5;
    int width = SCREEN_WIDTH, height = SCREEN_HEIGHT;

    const char *labels[NUMMENU] = {"Voenmeh", "SYRE", "ERYS", "STV3", "Manchester United"};
    bool hovered[NUMMENU] = {false, false, false, false};
    bool selected[NUMMENU] = {false, false, false, false};
    SDL_Color color[2] = {{255, 255, 255},
                          {0,   0,   255}};
    SDL_Surface *menus[NUMMENU]{};
    SDL_Rect pos[NUMMENU]{};
    public:

    ChoiceBackground();

    void handleEvent(SDL_Event e, bool * isScene);
};

#endif //PINGPONG_CHOICEBACKGROUND_H
