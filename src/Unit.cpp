#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"
#include "debug.hpp"

void Unit::move() {
    // Testing for player not to be stucked with some solid object
    sf::Time delta_time = clock->restart();
    sf::FloatRect bounds = sprite->get_sprite().getGlobalBounds();

    bounds.top += solid_height;
    bounds.height -= solid_height;

    bounds.left += direction.x * speed * delta_time.asMilliseconds();
    bounds.top += direction.y * speed * delta_time.asMilliseconds();

    unsigned short block_size = 100; // TODO: Change to actual tile size

    unsigned short left = bounds.left / block_size;
    unsigned short right = (bounds.left + bounds.width) / block_size;

    unsigned short up = bounds.top / block_size;
    unsigned short down = (bounds.top + bounds.height) / block_size;

    if (direction != Directions::NullDirection)
        sprite->move(direction, speed*delta_time.asMilliseconds());
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

void Unit::set_solid_height(unsigned short height) {
    solid_height = height;
}
int Unit::get_position_x(){
    return sprite->get_sprite().getGlobalBounds().left;
}

int Unit::get_position_y(){
    return sprite->get_sprite().getGlobalBounds().top;
}