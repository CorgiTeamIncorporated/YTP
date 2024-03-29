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

    bool is_killed = false;
public:
    sf::Vector2f direction;

    Unit(AnimatedSprite* sprite, Dungeon* dungeon = nullptr, float speed = 0.5):
        sprite(sprite), dungeon_ptr(dungeon), health(100), speed(speed) {};

    void move(sf::Time delta);

    sf::Sprite& get_sprite();

    void set_solid_height(unsigned short height);
    void set_position(sf::Vector2f position);
    void set_speed(float speed);

    sf::FloatRect get_solid_bounds();
    sf::Vector2f get_position();
    sf::FloatRect get_bounds();

    bool killed();
  
    friend class Dungeon;
};