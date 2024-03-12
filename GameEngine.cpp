#include "GameEngine.h"
#include <iostream>
#include <cctype>

GameEngine::GameEngine() {
    computerPlayer.readPatternFromFile("frequencies.txt");
}

void GameEngine::setComputerPlayerStrategy(const std::string& strategy) {
    computerPlayer.setStrategy(strategy);
}

int GameEngine::determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // Draw
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        return 1; // User wins
    } else {
        return -1; // Computer wins
    }
}

void GameEngine::playGame() {
    std::cout << "Rock, Paper, Scissors Game against the Computer!\n";
    std::cout << "Enter R for Rock, P for Paper, S for Scissors, Q to quit:\n";

    while (true) {
        Choice userChoice = humanPlayer.makeMove();
        if (GameChoice::choiceToString(userChoice) == "Unknown") {
            computerPlayer.writePatternToFile("frequencies.txt");
            break;
        }

        Choice computerChoice = computerPlayer.makeMove();
        computerPlayer.updatePattern(GameChoice::choiceToString(userChoice)[0]);

        std::cout << "You chose " << GameChoice::choiceToString(userChoice) << ".\n";
        std::cout << "Computer chose " << GameChoice::choiceToString(computerChoice) << ".\n";

        int winner = determineWinner(userChoice, computerChoice);
        if (winner == 0) {
            std::cout << "It's a draw!\n";
        } else if (winner == 1) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }
    }
}
