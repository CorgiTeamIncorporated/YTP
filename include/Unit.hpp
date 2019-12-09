#include "AnimatedSprite.hpp"
#include "Directions.hpp"
#pragma once

class Dungeon;

class Unit {
protected:
    unsigned short solid_height;
    signed short health;
    float speed;

    AnimatedSprite* sprite;
    Dungeon* dungeon_ptr;
public:
    sf::Vector2f direction;

    Unit(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        sprite(sprite), dungeon_ptr(dungeon), health(100) {};

    void move(sf::Time delta);

    sf::Sprite& get_sprite();

    void set_solid_height(unsigned short height);
    void set_position(sf::Vector2f position);
    void set_speed(float speed);

    sf::FloatRect get_solid_bounds();
    sf::Vector2f get_position();
    sf::FloatRect get_bounds();
  
    friend class Dungeon;
};