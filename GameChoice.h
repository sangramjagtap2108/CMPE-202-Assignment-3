#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include <string>
#include "Choice.h" // Ensure this file exists and contains the Choice enum

class GameChoice {
public:
    static std::string choiceToString(Choice c);
    static Choice charToChoice(char c);
    static Choice winningChoiceAgainst(Choice c);
};

#endif // GAMECHOICE_H
