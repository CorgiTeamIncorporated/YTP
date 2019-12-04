#include "Directions.hpp"
#include "Unit.hpp"
#include "Scenes/Dungeon.hpp"
#include <iostream>

void Unit::move(sf::Time delta_time) {
    // Testing for player not to be stucked with some solid object

    // `bounds` are boundaries of player on the next tick
    sf::FloatRect bounds = sprite->get_sprite().getGlobalBounds();

    bounds.top += solid_height;
    bounds.height -= solid_height;

    float time_as_float = static_cast<float>(delta_time.asMicroseconds());

    bounds.left += direction.x * speed * time_as_float * static_cast<float>(1e-3);
    bounds.top += direction.y * speed * time_as_float * static_cast<float>(1e-3);

    unsigned short block_size = dungeon_ptr->tile_size;

    unsigned short left = bounds.left / block_size;
    unsigned short right = (bounds.left + bounds.width) / block_size;

    unsigned short up = bounds.top / block_size;
    unsigned short down = (bounds.top + bounds.height) / block_size;

    for (int i = up; i <= down; ++i) {
        for (int j = left; j <= right; ++j) {
            if (i < 0 || i >= dungeon_ptr->current_room->height)
                continue;

            if (j < 0 || j >= dungeon_ptr->current_room->width)
                continue;

            MapObject* object = dungeon_ptr->current_room->map[i][j];

            if (object->solid_height != 0) {
                if (object->solid_part.getGlobalBounds().intersects(bounds)) {
                    return;
                }
            }
        }
    }

    if (direction != Directions::NullDirection)
        sprite->move(direction, speed, delta_time);
}

sf::Sprite& Unit::get_sprite() {
    return sprite->get_sprite();
}

void Unit::set_speed(float speed) {
    this->speed = speed;
}

void Unit::set_solid_height(unsigned short height) {
    solid_height = height;
}