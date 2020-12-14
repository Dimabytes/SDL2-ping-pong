#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "SDL.h"
#include "../MenuItem.h"

#ifndef PINGPONG_RECORDS_H
#define PINGPONG_RECORDS_H

class Records: MenuItem {
    std::vector<std::pair<std::string, int>> players;
    int playersQuantity = 0;
public:
    void restart() override;

    Records()=default;

    void handleEvent(SDL_Event e, bool * isScene) override;
};

#endif //PINGPONG_RECORDS_H
