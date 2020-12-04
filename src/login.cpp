#include "globals.h"
#include "login.h"
#include "utils.h"
#include <string>

void inputName(const std::string& label, Profile* profile) {
    bool isLoop = true;
    int width, height;
    SDL_Event e;
    while (isLoop) {
        while ( SDL_PollEvent( &e ) ) {

            switch (e.type) {
                case SDL_TEXTINPUT:
                    profile->name += e.text.text;
                    break;
                case SDL_KEYDOWN:
                    if (e.key.keysym.sym == SDLK_BACKSPACE && !profile->name.empty()) {
                        profile->name.pop_back();
                    }
                    if (e.key.keysym.sym == SDLK_RETURN && !profile->name.empty()) {
                        isLoop = false;
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        renderText(label, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 60, CLR_WHITE);
        if ( !profile->name.empty() ) {
            width = SCREEN_WIDTH, height = SCREEN_HEIGHT;
            SDL_Surface *surfaceGroup = TTF_RenderUTF8_Solid(font25, profile->name.c_str(), CLR_WHITE);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surfaceGroup);
            SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
            SDL_Rect rectGroup = {SCREEN_WIDTH / 2 - width / 2, SCREEN_HEIGHT / 2 - height / 2, width, height};
            SDL_RenderCopy(gRenderer, texture, nullptr, &rectGroup);
            SDL_DestroyTexture(texture);
            SDL_FreeSurface(surfaceGroup);
        }

        SDL_RenderPresent( gRenderer );
    }
}

void login() {
    inputName("Игрок 1:", &profile1);
    inputName("Игрок 2:", &profile2);
}

