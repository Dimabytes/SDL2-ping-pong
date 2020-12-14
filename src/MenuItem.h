#include "SDL.h"
#include "backButton.h"

#ifndef PINGPONG_MENUITEM_H
#define PINGPONG_MENUITEM_H

 class MenuItem{

 protected:
    BackButton backButton;


public:
    virtual void restart() {};
    virtual void handleEvent(SDL_Event e, bool * isScene) = 0;
};

#endif //PINGPONG_MENUITEM_H
