#include "game.h"
#include "Plank.h"
#include "../globals.h"
#include "SDL.h"

Game::Game(SDL_Renderer * renderer){
    gRenderer = renderer;
    dot.init(gRenderer);
    plank1.init(gRenderer);
    plank2.init(gRenderer);
};

void Game::handleEvent(SDL_Event * e) {

    while (SDL_PollEvent(e)) {
        plank1.handleEvent(*e, 0);
        plank2.handleEvent(*e, 1);
    }

    plank1.move();
    plank2.move();
    dot.move(plank1.plankCollider, plank2.plankCollider);

    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(gRenderer);

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
    }

    plank1.render(gRenderer);
    plank2.render(gRenderer);
    dot.render(gRenderer);
}
