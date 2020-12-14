#include "game.h"
#include "Plank.h"
#include "../globals.h"
#include "../utils.h"
#include "../backButton.h"
#include "SDL.h"

Game::Game(){
    dot.init();
    dot2.init();
    plank1.init();
    plank2.init();
}

void Game::restart() {
    profile1.points = 10;
    profile2.points = 10;

    isDot2 = false;
}

void Game::handleEvent(SDL_Event e, bool * isScene) {
    while (SDL_PollEvent(&e)) {
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
            *isScene = false;
            break;
        }
        plank1.handleEvent(e, 0);
        plank2.handleEvent(e, 1);
        backButton.handleEvent(e, isScene);
    }


    SDL_RenderClear(gRenderer);
    drawBackground();


    backButton.render();
    plank1.move();
    plank2.move();
    dot.move(plank1.plankCollider, plank2.plankCollider, &isDot2);

    if(isDot2){
        dot2.move(plank1.plankCollider, plank2.plankCollider, &isDot2);
    }

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_Rect rect;
    rect.x = SCREEN_WIDTH / 2 - 150;
    rect.y = 0;
    rect.w = 300;
    rect.h = 60;
    SDL_RenderFillRect(gRenderer, &rect);

    renderText(profile1.name, SCREEN_WIDTH / 2 - 150, 5, CLR_WHITE);
    renderText(profile1.points, SCREEN_WIDTH / 2 - 150, 30, CLR_WHITE);

    renderText(profile2.name, SCREEN_WIDTH / 2, 5, CLR_WHITE);
    renderText(profile2.points, SCREEN_WIDTH / 2, 30, CLR_WHITE);

    plank1.render();
    plank2.render();
    dot.render();
    if(isDot2){
        dot2.render();
    }

    if(profile1.points < 1){
        profile1.updateRecord(profile1.record - 1);
        profile2.updateRecord(profile2.record + 1);
        *isScene = false;
    }

    if(profile2.points < 1){
        profile2.updateRecord(profile2.record - 1);
        profile1.updateRecord(profile1.record + 1);
        *isScene = false;
    }

}
