#ifndef GAMECHOICESERVICE_H
#define GAMECHOICESERVICE_H

#include "GameChoice.h"

class GameChoiceService {
public:
    virtual ~GameChoiceService() = default;
    virtual Choice winningChoiceAgainst(Choice c) = 0;
};

#endif // GAMECHOICESERVICE_H
