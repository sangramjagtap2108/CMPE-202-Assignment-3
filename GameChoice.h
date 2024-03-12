#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include <string>

enum Choice {
    ROCK,
    PAPER,
    SCISSORS
};

class GameChoice {
public:
    static std::string choiceToString(Choice c);
    static Choice charToChoice(char c);
    static Choice winningChoiceAgainst(Choice c);
};

#endif // GAMECHOICE_H
