#include "Enemies/AbstractEnemy.hpp"
#include "Directions.hpp"
#pragma once

class FireBall: public AbstractEnemy {
public: 
    FireBall(AnimatedSprite* sprite, Dungeon* dungeon = nullptr): 
        AbstractEnemy(sprite, dungeon), direction(Directions::Up) {};

    void set_direction(sf::Vector2f direction);
    void ai_move(sf::Time delta_time);
    sf::Vector2f direction;
private:
    bool has_attacked = false;

    bool intersects_with_solid_blocks();
    bool intersects_with_doors();
};