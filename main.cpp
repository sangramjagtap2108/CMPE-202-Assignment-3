#include <iostream>
#include <string>
#include "RockPaperScissorsGame.h"

int main() {
    RockPaperScissorsGame game;

    std::string strategy;
    std::cout << "Choose strategy (random/smart): ";
    std::cin >> strategy;

    game.setStrategy(strategy);
    game.start();

    return 0;
}
