#ifndef GAMECHOICESERVICEIMPL_H
#define GAMECHOICESERVICEIMPL_H

#include "GameChoiceService.h"
#include "GameChoice.h"

class GameChoiceServiceImpl : public GameChoiceService {
public:
    Choice winningChoiceAgainst(Choice c) override {
        return GameChoice::winningChoiceAgainst(c);
    }
};

#endif // GAMECHOICESERVICEIMPL_H
