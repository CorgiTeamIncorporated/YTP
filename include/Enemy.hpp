#include "Unit.hpp"
#pragma once

class Enemy: public Unit {
public:
    Enemy(AnimatedSprite* sprite, Game* game = nullptr):
      Unit(sprite, game) {};

    virtual void ai_move() = 0;
};