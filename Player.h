#ifndef PLAYER_H
#define PLAYER_H

#include "GameChoice.h"

class Player {
public:
    virtual ~Player() = default;
    virtual Choice makeMove() = 0;
};

#endif // PLAYER_H
