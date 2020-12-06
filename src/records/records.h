#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "SDL.h"

#ifndef PINGPONG_RECORDS_H
#define PINGPONG_RECORDS_H

class Records {
    std::vector<std::pair<std::string, int>> players;

    int playersQuantity = 0;
public:
    void restart();

    Records()=default;

    void handleEvent(SDL_Event e, bool * isScene);
};

#endif //PINGPONG_RECORDS_H
