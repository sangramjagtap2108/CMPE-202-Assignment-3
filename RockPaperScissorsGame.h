#ifndef ROCKPAPERSCISSORSGAME_H
#define ROCKPAPERSCISSORSGAME_H

#include "GameEngine.h"

class RockPaperScissorsGame {
    GameEngine* engine;

public:
    RockPaperScissorsGame(GameEngine* eng) : engine(eng) {}
    void start();
    void setStrategy(const std::string& strategy);
};

#endif // ROCKPAPERSCISSORSGAME_H
