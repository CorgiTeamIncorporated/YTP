#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"

void Unit::move(const sf::Vector2f delta) {
    sprite->move(delta);
}

sf::Sprite& Unit::get_sprite() {
    return sprite->get_sprite();
}

void Unit::set_game_ptr(Game* ptr) {
    game_ptr = ptr;
}