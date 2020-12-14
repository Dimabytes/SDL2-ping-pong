#include "SDL.h"
#ifndef PINGPONG_RULES_H
#define PINGPONG_RULES_H
#include "../MenuItem.h"

class Rules: MenuItem {
public:
    Rules()=default;

    void handleEvent(SDL_Event e, bool * isScene) override;
};

#endif //PINGPONG_RULES_H
