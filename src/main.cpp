#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "collision.h"
#include "Dot.h"
#include "Plank.h"
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

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
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    return success;
}


void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;
    SDL_Quit();
}

int main() {
    if (!init()) {
        printf("FAILED TO INITIALIZE\n");
        return 1;
    }

    Dot dot;
    Plank plank1(20, SCREEN_HEIGHT / 2 - 35);
    Plank plank2(SCREEN_WIDTH - 40, SCREEN_HEIGHT / 2 - 35);
    if (!dot.init(gRenderer) || !plank1.init(gRenderer) || !plank2.init(gRenderer)) {
        printf("MEDIA LOAD FAILED\n");
        close();
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            plank1.handleEvent(e, 0);
            plank2.handleEvent(e, 1);
        }

        plank1.move(SCREEN_HEIGHT);
        plank2.move(SCREEN_HEIGHT);
        dot.move(plank1.plankCollider, plank2.plankCollider, SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(gRenderer);

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
            SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
        }

        plank1.render(gRenderer);
        plank2.render(gRenderer);
        dot.render(gRenderer);
        SDL_RenderPresent(gRenderer);
    }
    close();
    return 0;
}
