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

sf::FloatRect Unit::get_solid_bounds() {
    sf::FloatRect solid_part = sprite->get_bounds();
    solid_part.top += solid_part.height - solid_height;
    solid_part.height = solid_height;

    return solid_part;
}

sf::Vector2f Unit::get_position() {
    return sprite->get_position();
}

void Unit::set_position(sf::Vector2f position) {
    // This function sets the player's position considering
    // the player a square block with a side equal to
    // `tile_size` and a sprite aligned to the bottom

    float delta = dungeon_ptr->tile_size - sprite->get_bounds().height;
    sprite->set_position(position + sf::Vector2f(0, delta));
}

sf::FloatRect Unit::get_bounds() {
    // Returns bounds of the player considering the player
    // a square with a side equal to `tile_size`

    sf::FloatRect bounds = sprite->get_bounds();
    bounds.top -= dungeon_ptr->tile_size - sprite->get_bounds().height;
    bounds.height = dungeon_ptr->tile_size;

    return bounds;
}