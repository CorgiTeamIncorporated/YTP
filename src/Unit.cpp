#include "Directions.hpp"
#include "Unit.hpp"
#include "Scenes/Dungeon.hpp"
// #include "debug.hpp"

void Unit::move(sf::Time delta_time) {
    // Testing for player not to be stucked with some solid object
    sf::FloatRect bounds = sprite->get_sprite().getGlobalBounds();

    bounds.top += solid_height;
    bounds.height -= solid_height;

    bounds.left += direction.x * speed * delta_time.asMilliseconds();
    bounds.top += direction.y * speed * delta_time.asMilliseconds();

    unsigned short block_size = dungeon_ptr->tile_size;

    unsigned short left = bounds.left / block_size;
    unsigned short right = (bounds.left + bounds.width) / block_size;

    unsigned short up = bounds.top / block_size;
    unsigned short down = (bounds.top + bounds.height) / block_size;

    for (int i = left; i <= right; ++i) {
        for (int j = up; j <= down; ++j) {
            MapObject* object = dungeon_ptr->current_room->map[i][j];

            if (object->solid_height != 0) {
                if (object->solid_part.getGlobalBounds().intersects(bounds)) {
                    return; // TODO: move player in opposite direction until intersects
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