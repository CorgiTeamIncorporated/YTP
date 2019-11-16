#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"

void Unit::move() {
    if (direction != Directions::NullDirection)
        sprite->move(direction, speed);
}

sf::Sprite& Unit::get_sprite() {
    return sprite->get_sprite();
}

void Unit::set_game_ptr(Game* ptr) {
    game_ptr = ptr;
}

void Unit::set_speed(float speed) {
    this->speed = speed;
}