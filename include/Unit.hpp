#include "AnimatedSprite.hpp"
#include "Directions.hpp"
#pragma once

class Game;

class Unit {
protected:
    AnimatedSprite* sprite; Game* game_ptr;
    unsigned int speed;
public:
    Unit(AnimatedSprite* sprite, Game* game = nullptr):
      sprite(sprite), game_ptr(game) {};

    void move(const sf::Vector2f delta);
    sf::Sprite& get_sprite();
    void set_game_ptr(Game* ptr);
    void set_speed(float speed);
};