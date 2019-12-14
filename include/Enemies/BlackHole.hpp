#include "Enemies/AbstractEnemy.hpp"
#pragma once

class BlackHole: public AbstractEnemy {
public: 
    BlackHole(AnimatedSprite* sprite, Dungeon* dungeon = nullptr): 
        AbstractEnemy(sprite, dungeon) {};

    BlackHole():
        AbstractEnemy(new AnimatedSprite(
            new sf::Sprite(GameSprites::BlackHole), &BlackHoleConfig)) {};

    void ai_move(sf::Time delta_time);

private:
    sf::Time accumulator = sf::Time::Zero;
};