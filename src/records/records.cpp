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
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    for(int i = 0; i < playersQuantity; i++){
        renderText(players[i].first, 30, 20 + i * 45, CLR_ORANGE);
        renderText(players[i].second, 300, 20 + i * 45, CLR_ORANGE);
    }

}