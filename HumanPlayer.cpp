#include "HumanPlayer.h"
#include "GameChoice.h"
#include <iostream>
#include <cctype>

Choice HumanPlayer::makeMove() {
    char userMove;
    std::cout << "> ";
    std::cin >> userMove;
    return GameChoice::charToChoice(toupper(userMove));
}
