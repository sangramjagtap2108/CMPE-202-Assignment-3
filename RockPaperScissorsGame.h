#ifndef ROCKPAPERSCISSORSGAME_H
#define ROCKPAPERSCISSORSGAME_H

#include "GameEngine.h"

class RockPaperScissorsGame {
    GameEngine engine;

public:
    void start();
    void setStrategy(const std::string& strategy);
};

#endif // ROCKPAPERSCISSORSGAME_H
