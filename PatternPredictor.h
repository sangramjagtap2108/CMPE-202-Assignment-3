#ifndef PATTERNPREDICTOR_H
#define PATTERNPREDICTOR_H

#include <unordered_map>
#include <string>
#include "GameChoice.h"

class PatternPredictor {
    std::unordered_map<std::string, std::unordered_map<char, int>> frequencyMap;
    std::string sequence;
    const int N = 5;

public:
    PatternPredictor();
    Choice predictNextMove();
    void updateFrequencyMap(char move);
    void readFrequenciesFromFile(const std::string &filename);
    void writeFrequenciesToFile(const std::string &filename);
};

#endif // PATTERNPREDICTOR_H
