#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    ~HumanPlayer() override = default;
    Choice makeMove() override;
};

#endif // HUMANPLAYER_H
