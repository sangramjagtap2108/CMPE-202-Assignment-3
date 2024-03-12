#include "HumanPlayer.h"
#include <iostream>

Choice HumanPlayer::makeMove() {
    char userMove;
    std::cout << "> ";
    std::cin >> userMove;
    return GameChoice::charToChoice(toupper(userMove));
}
