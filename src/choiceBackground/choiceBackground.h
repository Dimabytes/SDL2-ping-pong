#include "SDL.h"
#include "../globals.h"
#include "../backButton.h"

#ifndef PINGPONG_CHOICEBACKGROUND_H
#define PINGPONG_CHOICEBACKGROUND_H

class ChoiceBackground {
    int x = 0, y = 0;
    static const int NUMMENU = 5;
    int width = SCREEN_WIDTH, height = SCREEN_HEIGHT;

    const char *labels[NUMMENU] = {"Voenmeh", "SYRE", "ERYS", "STV3", "Manchester United"};
    bool hovered[NUMMENU] = {false, false, false, false};
    SDL_Color color[2] = {CLR_WHITE, CLR_GREEN};
    SDL_Surface *menus[NUMMENU]{};
    SDL_Rect pos[NUMMENU]{};

    BackButton backButton;
    public:

    ChoiceBackground();

    void handleEvent(SDL_Event e, bool * isScene);
};

#endif //PINGPONG_CHOICEBACKGROUND_H
