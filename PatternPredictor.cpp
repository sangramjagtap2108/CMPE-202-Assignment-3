#include "PatternPredictor.h"
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <ctime>   
#include <iostream> 

PatternPredictor::PatternPredictor() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

Choice PatternPredictor::predictNextMove() {
    if (sequence.length() < N - 1) {
        return static_cast<Choice>(rand() % 3);
    }

    std::string recentPattern = sequence.substr(sequence.length() - (N - 1));
    if (frequencyMap.find(recentPattern) == frequencyMap.end()) {
        return static_cast<Choice>(rand() % 3);
    }

    char mostLikelyMove = 'R'; 
    int maxFrequency = -1;
    for (auto &moveFreq : frequencyMap[recentPattern]) {
        if (moveFreq.second > maxFrequency) {
            maxFrequency = moveFreq.second;
            mostLikelyMove = moveFreq.first;
        }
    }

    return GameChoice::charToChoice(mostLikelyMove);
}

void PatternPredictor::updateFrequencyMap(char move) {
    if (sequence.length() == N - 1) {
        frequencyMap[sequence][move]++;
    }
    sequence += move;
    if (sequence.length() > N - 1) {
        sequence.erase(sequence.begin());
    }
}

void PatternPredictor::readFrequenciesFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string pattern;
            getline(iss, pattern, ':');
            pattern.erase(pattern.end() - 1);

            std::unordered_map<char, int> moves;
            std::string moveFreqPair;
            while (getline(iss, moveFreqPair, ',')) {
                if(moveFreqPair.empty()) continue; 
                std::istringstream ss(moveFreqPair);
                char move;
                int freq;
                ss >> move >> freq;
                moves[move] = freq;
            }
            frequencyMap[pattern] = moves;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void PatternPredictor::writeFrequenciesToFile(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &entry : frequencyMap) {
            file << entry.first << ": ";
            for (const auto &moveFreq : entry.second) {
                file << moveFreq.first << " " << moveFreq.second << ",";
            }
            file << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
