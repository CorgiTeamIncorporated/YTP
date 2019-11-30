#include "AnimatedSprite.hpp"
#include "Directions.hpp"
#pragma once

class Dungeon;

class Unit {
protected:
    unsigned short solid_height;
    AnimatedSprite* sprite;
    Dungeon* dungeon_ptr;
    float speed;
public:
    sf::Vector2f direction;

    Unit(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        sprite(sprite), dungeon_ptr(dungeon) {};

    void move(sf::Time delta);

    sf::Sprite& get_sprite();

    void set_solid_height(unsigned short height);
    void set_speed(float speed);
  
    friend class Dungeon;
};