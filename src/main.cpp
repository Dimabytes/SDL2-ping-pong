#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "game/game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "globals.h"
#include "utils.h"
#include "choiceBackground/choiceBackground.h"
#include "rules/rules.h"
#include "login.h"

void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;
    SDL_Quit();
}

int showmenu() {
    int x, y;
    bool isMenu;
    const int NUMMENU = 4;
    int width = SCREEN_WIDTH, height = SCREEN_HEIGHT;

    const char *labels[NUMMENU] = {"Правила игры", "Рекорды", "Смена заднего фона", "Играть"};
    SDL_Surface *menus[NUMMENU];
    bool hovered[NUMMENU] = {false, false, false, false};
    bool selected[NUMMENU] = {false, false, false, false};
    SDL_Color color[2] = {CLR_WHITE, CLR_GREEN};
    SDL_Rect pos[NUMMENU];

    Game game;
    ChoiceBackground choiceBackground;

    for (int i = 0; i < NUMMENU; ++i) {
        menus[i] = TTF_RenderUTF8_Solid(font25, labels[i], color[0]);
        pos[i].x = 30;
        pos[i].y = 100 + i * 60;
        pos[i].w = menus[i]->clip_rect.w;
        pos[i].h = menus[i]->clip_rect.h;
    }

    SDL_Event event;
    while (true) {
        switch (event.type) {
            case SDL_QUIT:
                for (auto & menu : menus) {
                    SDL_FreeSurface(menu);
                }
                close();
                return 1;
        }
        for (int i = 0; i < NUMMENU; ++i) {
            if(selected[i] && i == 0){
                rulesHandleEvent(event, &selected[i]);
                break;
            }
            if(selected[i] && i == 3){
                game.handleEvent(&event, &selected[i]);
                break;
            }
            if(selected[i] && i == 2){
                choiceBackground.handleEvent(event, &selected[i]);
                break;
            }
        }
        isMenu = true;
        for(bool i : selected){
            if(i){
                isMenu = false;
                break;
            }
        }

        SDL_RenderPresent(gRenderer);

        if(!isMenu){
            continue;
        }

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;
                    for (int i = 0; i < NUMMENU; i++) {
                        if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                            y >= pos[i].y && y <= pos[i].y + pos[i].h) {
                            if (!hovered[i]) {
                                hovered[i] = true;
                                SDL_FreeSurface(menus[i]);
                                menus[i] = TTF_RenderUTF8_Solid(font25, labels[i], color[1]);
                            }
                        } else if (hovered[i]) {
                            hovered[i] = false;
                            SDL_FreeSurface(menus[i]);
                            menus[i] = TTF_RenderUTF8_Solid(font25, labels[i], color[0]);
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:

                    x = event.button.x;
                    y = event.button.y;
                    for (int i = 0; i < NUMMENU; i += 1) {
                        if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                            y >= pos[i].y && y <= pos[i].y + pos[i].h) {
                            selected[i] = true;

                            if(i == 3){
                                game.restart();
                            }
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        for (auto & menu : menus) {
                            SDL_FreeSurface(menu);
                        }
                        close();
                        return 1;
                    }
            }
        }

        SDL_RenderClear(gRenderer);
        drawBackground();
        for (int i = 0; i < NUMMENU; i += 1) {
            SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, menus[i]);
            SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
            SDL_Rect rectGroup = {pos[i].x, pos[i].y, width, height};
            SDL_RenderCopy(gRenderer, texture, nullptr, &rectGroup);
            SDL_DestroyTexture(texture);
        }
    }
}

bool init() {
    srand(time(nullptr) % 100);
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("failed to INITIALIZE!!\n");
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }
        gWindow = SDL_CreateWindow("VOENMEH BETTER THAN ALL", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            printf("failed to create window\n");
            success = false;
        } else {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr) {
                printf("failed to create renderer\n");
                success = false;
            }
        }
    }

    return success;
}

int main() {
    if (!init()) {
        printf("FAILED TO INITIALIZE\n");
        return 1;
    }
    setBackground("img/voenmeh.jpg");
    TTF_Init();
    font25 = TTF_OpenFont("fonts/font.ttf", 25);
    font15 = TTF_OpenFont("fonts/font.ttf", 15);

    login();
    showmenu();
    close();
    return 0;
}
