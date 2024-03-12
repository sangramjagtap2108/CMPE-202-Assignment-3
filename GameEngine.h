#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class GameEngine {
    HumanPlayer humanPlayer;
    ComputerPlayer computerPlayer;

public:
    GameEngine();
    void playGame();
    void setComputerPlayerStrategy(const std::string& strategy);
    int determineWinner(Choice userChoice, Choice computerChoice);
};

#endif // GAMEENGINE_H
