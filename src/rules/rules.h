#include "SDL.h"
#include "../backButton.h"
#ifndef PINGPONG_RULES_H
#define PINGPONG_RULES_H

void rulesHandleEvent(SDL_Event e, bool *isScene);

class Rules {
    BackButton backButton;
public:
    Rules()=default;

    void handleEvent(SDL_Event e, bool * isScene);
};

#endif //PINGPONG_RULES_H
