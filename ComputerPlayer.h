#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "PatternPredictor.h"
#include "GameChoice.h"
#include <cstdlib>
#include <ctime>
#include <string>

class ComputerPlayer : public Player {
    PatternPredictor predictor;
    enum Strategy { RANDOM, SMART };
    Strategy currentStrategy;

public:
    ComputerPlayer();
    ~ComputerPlayer() override = default;
    
    Choice makeMove() override;
    void updatePattern(char move);
    void readPatternFromFile(const std::string& filename);
    void writePatternToFile(const std::string& filename);
    void setStrategy(const std::string& strategy);

private:
    Choice winningChoiceAgainst(Choice c);
    Choice randomChoice();
    Strategy stringToStrategy(const std::string& strategy);
};

#endif
