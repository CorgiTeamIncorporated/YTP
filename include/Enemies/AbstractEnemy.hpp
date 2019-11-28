#include "Unit.hpp"
#pragma once

class AbstractEnemy: public Unit {
public:
    AbstractEnemy(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        Unit(sprite, dungeon) {};

    virtual void ai_move() = 0;
};