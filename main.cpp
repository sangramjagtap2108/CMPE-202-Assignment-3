#include <iostream>
#include "RockPaperScissorsGame.h"
#include "GameChoiceServiceImpl.h"

int main() {
    GameChoiceServiceImpl gameChoiceService; // Instantiate your service
    GameEngine engine(&gameChoiceService); // Inject service into engine
    RockPaperScissorsGame game(&engine); // Adjust RockPaperScissorsGame constructor accordingly

    std::string strategy;
    std::cout << "Choose strategy (random/smart): ";
    std::cin >> strategy;

    game.setStrategy(strategy);
    game.start();

    return 0;
}
