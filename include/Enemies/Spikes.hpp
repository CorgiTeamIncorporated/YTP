#include "Enemies/AbstractEnemy.hpp"
#pragma once

class Spikes: public AbstractEnemy {
    public: 
    Spikes(AnimatedSprite* sprite, Dungeon* dungeon = nullptr): 
        AbstractEnemy(sprite, dungeon) {};

    void make_visible();
    void ai_move(sf::Time delta_time);
    private:

    bool is_visible = false;
    sf::Time life_time = sf::seconds(2);
    sf::Clock timer;
};