#include "AnimatedSprite.hpp"
#include "Directions.hpp"
#pragma once

class Game;

class Unit {
protected:
    unsigned short solid_height;
    AnimatedSprite* sprite;
    sf::Clock* clock;
    Game* game_ptr;
    float speed;
public:
    sf::Vector2f direction;
  
    Unit(AnimatedSprite* sprite, Game* game = nullptr):
      sprite(sprite), game_ptr(game), clock(new sf::Clock) {};

    void move();

    sf::Sprite& get_sprite();

    void set_game_ptr(Game* ptr);
    void set_solid_height(unsigned short height);
    void set_speed(float speed);
    unsigned short get_position_x();
    unsigned short get_position_y();
};