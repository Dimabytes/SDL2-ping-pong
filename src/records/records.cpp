#include "records.h"
#include <iostream>
#include <algorithm>
#include "../globals.h"
#include "../utils.h"

bool sortByVal(const std::pair<std::string, int> &a,
               const std::pair<std::string, int> &b)
{
    return (a.second > b.second);
}

void Records::restart() {
    std::string s;
    std::string name;
    std::ifstream file("records.txt");
    players.clear();
    while(getline(file, s)){
        if(!s.empty()){
            s = s.substr(2);
            name = s.substr(0, s.find("__"));
            players.push_back(std::make_pair(name, std::stoi(s.substr(name.length() + 3))));
        }
    }

    sort(players.begin(), players.end(), sortByVal);
    int size = players.size();
    playersQuantity = size > 10 ? 10 : size;
}

void Records::handleEvent(SDL_Event e, bool *isScene) {
    while (SDL_PollEvent(&e)) {
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
            *isScene = false;
            break;
        }
        backButton.handleEvent(e, isScene);
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);
    renderText("Разница побед и поражений", SCREEN_WIDTH / 2 - 180, 0, CLR_ORANGE);
    backButton.render();
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(gRenderer, 280, 60, 280, 60 + playersQuantity * 40);
    for(int i = 0; i < playersQuantity; i++){
        SDL_RenderDrawLine(gRenderer, 0, 60 + i * 40, SCREEN_WIDTH, 60 + i * 40);
        renderText(players[i].first, 30, 60 + i * 40, CLR_ORANGE);
        renderText(players[i].second, 300, 60 + i * 40, CLR_ORANGE);
    }
    SDL_RenderDrawLine(gRenderer, 0, 60 + playersQuantity * 40, SCREEN_WIDTH, 60 + playersQuantity * 40);

}