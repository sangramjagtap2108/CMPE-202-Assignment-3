#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameChoiceServiceImpl.h"


class GameEngine {
    
private:
    GameChoiceService* gameChoiceService; 
    ComputerPlayer computerPlayer; 
    HumanPlayer humanPlayer;

public:
    GameEngine(GameChoiceService* gcs);
    void playGame();
    void setComputerPlayerStrategy(const std::string& strategy);
    int determineWinner(Choice userChoice, Choice computerChoice);
};

#endif // GAMEENGINE_H
