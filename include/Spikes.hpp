#include "Enemies/AbstractEnemy.hpp"
#pragma once

class Spikes: public AbstractEnemy {
public: 
    Spikes(AnimatedSprite* sprite, Dungeon* dungeon = nullptr): 
        AbstractEnemy(sprite, dungeon) {};

    void ai_move(sf::Time delta_time);
    void make_visible();

private:
    sf::Time accumulator = sf::Time::Zero;
    sf::Time life_time = sf::seconds(2);
    bool has_attacked = false;
    bool is_visible = false;
};