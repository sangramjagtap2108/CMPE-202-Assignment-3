#ifndef ICHOICECONVERTER_H
#define ICHOICECONVERTER_H

#include <string>
#include "Choice.h"

class IChoiceConverter {
public:
    virtual ~IChoiceConverter() = default;
    virtual std::string choiceToString(Choice c) = 0;
    virtual Choice charToChoice(char c) = 0;
    virtual Choice winningChoiceAgainst(Choice c) = 0;
};

#endif // ICHOICECONVERTER_H
