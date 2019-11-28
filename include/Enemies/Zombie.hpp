#include "Enemies/AbstractEnemy.hpp"
#pragma once

class Zombie: public AbstractEnemy {
public:
    Zombie(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        AbstractEnemy(sprite, dungeon) {};

    void ai_move(sf::Time delta_time);
};