#include "game.h"
#include "Plank.h"
#include "../globals.h"
#include "../utils.h"
#include "SDL.h"

Game::Game(){
    dot.init();
    plank1.init();
    plank2.init();
};

void Game::handleEvent(SDL_Event * e, bool * isScene) {

    while (SDL_PollEvent(e)) {
        if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE){
            *isScene = false;
            break;
        }
        plank1.handleEvent(*e, 0);
        plank2.handleEvent(*e, 1);
    }

    plank1.move();
    plank2.move();
    dot.move(plank1.plankCollider, plank2.plankCollider);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(gRenderer);

    for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
    }

    renderText(profile1.name, 20, 5, CLR_WHITE);
    renderText(profile1.points, 20, 30, CLR_WHITE);

    renderText(profile2.name, SCREEN_WIDTH - 100, 5, CLR_WHITE);
    renderText(profile2.points, SCREEN_WIDTH - 100, 30, CLR_WHITE);

    plank1.render();
    plank2.render();
    dot.render();
}
