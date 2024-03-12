#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() {
    srand(static_cast<unsigned int>(time(nullptr)));
    currentStrategy = SMART; 
}

Choice ComputerPlayer::winningChoiceAgainst(Choice c) {
    switch (c) {
        case ROCK: return PAPER;
        case PAPER: return SCISSORS;
        case SCISSORS: return ROCK;
        default: return ROCK;
    }
}

Choice ComputerPlayer::randomChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice ComputerPlayer::makeMove() {
    if (currentStrategy == RANDOM) {
        return randomChoice();
    } else {
        Choice predictedMove = predictor.predictNextMove();
        return winningChoiceAgainst(predictedMove);
    }
}

void ComputerPlayer::updatePattern(char move) {
    if (currentStrategy == SMART) {
        predictor.updateFrequencyMap(move);
    }
}

void ComputerPlayer::readPatternFromFile(const std::string& filename) {
    if (currentStrategy == SMART) {
        predictor.readFrequenciesFromFile(filename);
    }
}

void ComputerPlayer::writePatternToFile(const std::string& filename) {
    if (currentStrategy == SMART) {
        predictor.writeFrequenciesToFile(filename);
    }
}

void ComputerPlayer::setStrategy(const std::string& strategy) {
    currentStrategy = stringToStrategy(strategy);
}

ComputerPlayer::Strategy ComputerPlayer::stringToStrategy(const std::string& strategy) {
    if (strategy == "random") {
        return RANDOM;
    } else {
        return SMART;
    }
}


