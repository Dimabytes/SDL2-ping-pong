#include "choiceBackground.h"
#include "../utils.h"
#include "iostream"

ChoiceBackground::ChoiceBackground() {
    for (int i = 0; i < NUMMENU; ++i) {
        menus[i] = TTF_RenderUTF8_Solid(font25, labels[i], color[0]);
        pos[i].x = 30;
        pos[i].y = 100 + i * 60;
        pos[i].w = menus[i]->clip_rect.w;
        pos[i].h = menus[i]->clip_rect.h;
    }
}

void ChoiceBackground::handleEvent(SDL_Event e, bool *isScene) {

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_MOUSEMOTION:
                x = e.motion.x;
                y = e.motion.y;
                for (int i = 0; i < NUMMENU; i++) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h) {
                        if (!hovered[i]) {
                            hovered[i] = true;
                            SDL_FreeSurface(menus[i]);
                            menus[i] = TTF_RenderText_Solid(font25, labels[i], color[1]);
                        }
                    } else if (hovered[i]) {
                        hovered[i] = false;
                        SDL_FreeSurface(menus[i]);
                        menus[i] = TTF_RenderText_Solid(font25, labels[i], color[0]);
                    }
                }
                break;

            case SDL_MOUSEBUTTONDOWN:

                x = e.button.x;
                y = e.button.y;
                for (int i = 0; i < NUMMENU; i += 1) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h) {
                        if (i == 0){
                            setBackground("img/voenmeh.jpg");
                        } else if(i == 1){
                            setBackground("img/SYRE.jpg");
                        } else if(i == 2){
                            setBackground("img/ERYS.png");
                        } else if(i == 3){
                            setBackground("img/STV3.png");
                        } else if(i == 4){
                            setBackground("img/MU.jpg");
                        }
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    *isScene = false;
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