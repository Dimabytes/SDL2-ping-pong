#include "SDL.h"
#include "globals.h"
#include <string>


#ifndef PINGPONG_BACKBUTTON_H
#define PINGPONG_BACKBUTTON_H

class BackButton {
    int x = 0, y = 0;
    static const int NUMMENU = 1;
    int width = SCREEN_WIDTH, height = SCREEN_HEIGHT;

    const char *labels[NUMMENU] = {"Назад"};
    bool hovered[NUMMENU] = {false};
    SDL_Color color[2] = {CLR_BLACK, CLR_GREEN};
    SDL_Surface *menus[NUMMENU]{};
    SDL_Rect pos[NUMMENU]{};
public:

    BackButton();

    void handleEvent(SDL_Event e, bool * isScene);

    void render();

};

#endif //PINGPONG_BACKBUTTON_H
