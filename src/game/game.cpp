#include "game.h"
#include "Plank.h"
#include "../globals.h"
#include "../utils.h"
#include "SDL.h"

Game::Game(){
    dot.init();
    plank1.init();
    plank2.init();
}

void Game::restart() {
    profile1.points = 10;
    profile2.points = 10;
}

void Game::handleEvent(SDL_Event * e, bool * isScene) {

    while (SDL_PollEvent(e)) {
        if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE){
            *isScene = false;
            break;
        }
        plank1.handleEvent(*e, 0);
        plank2.handleEvent(*e, 1);
    }

    SDL_RenderClear(gRenderer);
    drawBackground();

    plank1.move();
    plank2.move();
    dot.move(plank1.plankCollider, plank2.plankCollider);

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); // the rect color (solid red)
    SDL_Rect rect; // the rectangle
    rect.x = SCREEN_WIDTH / 2 - 100;
    rect.y = 0;
    rect.w = 200;
    rect.h = 60;
    SDL_RenderFillRect(gRenderer, &rect);

    renderText(profile1.name, SCREEN_WIDTH / 2 - 100, 5, CLR_WHITE);
    renderText(profile1.points, SCREEN_WIDTH / 2 - 100, 30, CLR_WHITE);

    renderText(profile2.name, SCREEN_WIDTH / 2, 5, CLR_WHITE);
    renderText(profile2.points, SCREEN_WIDTH / 2, 30, CLR_WHITE);

    plank1.render();
    plank2.render();
    dot.render();

    if(profile1.points < 1){
        profile1.updateRecord(profile1.record - 1);
        profile2.updateRecord(profile2.record + 1);
        *isScene = false;
    }

    if(profile2.points < 1){
        profile2.updateRecord(profile1.record - 1);
        profile1.updateRecord(profile2.record + 1);
        *isScene = false;
    }

}
