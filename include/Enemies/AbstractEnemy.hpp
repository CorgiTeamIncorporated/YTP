#include "Unit.hpp"
#pragma once

class AbstractEnemy: public Unit {
public:
    AbstractEnemy(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        Unit(sprite, dungeon) {};

    virtual void ai_move(sf::Time delta_time) = 0;

    friend class GameRoom;
};