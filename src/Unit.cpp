#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"
#include "debug.hpp"

void Unit::move() {
    // Testing for player not to be stucked with some solid object
    sf::FloatRect bounds = sprite->get_sprite().getGlobalBounds();

    bounds.top += solid_height;
    bounds.height -= solid_height;

    bounds.left += direction.x * speed;
    bounds.top += direction.y * speed;

    unsigned short block_size = 100; // Change to actual tile size

    unsigned short left = bounds.left / block_size;
    unsigned short right = (bounds.left + bounds.width) / block_size;

    unsigned short up = bounds.top / block_size;
    unsigned short down = (bounds.top + bounds.height) / block_size;

    for (int i = left; i <= right; ++i) {
        for (int j = up; j <= down; ++j) {
            MapObject* object = game_ptr->current_room->map[i][j];

            if (object->solid_height != 0) {
                if (object->solid_part.getGlobalBounds().intersects(bounds)) {
                    return;
                }
            }
        }
    }

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

void Unit::set_solid_height(unsigned short height) {
    solid_height = height;
}