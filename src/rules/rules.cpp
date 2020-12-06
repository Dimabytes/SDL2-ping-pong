#include "rules.h"
#include "SDL.h"
#include <string>
#include "../utils.h"
#include "../globals.h"

void rulesHandleEvent(SDL_Event e, bool *isScene){
    while (SDL_PollEvent(&e)) {
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
            *isScene = false;
            break;
        }
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    renderText("Правила игры Пинг Понг", SCREEN_WIDTH / 2 - 120, 20, CLR_ORANGE);

    renderText("Два игрока. Каждый начинает с 10 очками.", 20, 60, CLR_ORANGE, font15);

    renderText("Каждый управляет своей платформой.", 20, 90, CLR_ORANGE, font15);

    renderText("1 игрок клавишами W и S", 20, 120, CLR_ORANGE, font15);

    renderText("2 игрок клавишами I и K", 20, 150, CLR_ORANGE, font15);

    renderText("За не отбитый шарик игрок теряет 1 очко", 20, 180, CLR_ORANGE, font15);

    renderText("Игра заканивается после потрери всез очков игроком", 20, 210, CLR_ORANGE, font15);

}