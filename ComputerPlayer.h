#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "GameChoiceService.h"
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
    ~ComputerPlayer() override = default;
    ComputerPlayer(GameChoiceService* gcs);
    Choice makeMove() override;
    void updatePattern(char move);
    void setStrategy(const std::string& strategy);

    // Add these declarations
    void readPatternFromFile(const std::string& filename);
    void writePatternToFile(const std::string& filename);

private:
    GameChoiceService* gameChoiceService;
    Choice randomChoice();
    Strategy stringToStrategy(const std::string& strategy);
};

#endif // COMPUTERPLAYER_H
