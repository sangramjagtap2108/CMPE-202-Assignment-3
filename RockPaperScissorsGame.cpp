#include "RockPaperScissorsGame.h"

void RockPaperScissorsGame::start() {
    engine.playGame();
}

void RockPaperScissorsGame::setStrategy(const std::string& strategy) {
    engine.setComputerPlayerStrategy(strategy);
}
