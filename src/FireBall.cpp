#include "Enemies/FireBall.hpp"
#include "Scenes/Dungeon.hpp"

bool FireBall::intersects_with_doors() {
    unsigned short tile_size = dungeon_ptr->tile_size;
    GameRoom* current_room = dungeon_ptr->current_room;

    float hor_middle = (current_room->width / 2) * tile_size;
    float ver_middle = (current_room->height / 2) * tile_size;
    float right_side = (current_room->width - 1) * tile_size;
    float bottom_side = (current_room->height - 1) * tile_size;

    sf::FloatRect up(hor_middle, 0, tile_size, tile_size);
    sf::FloatRect left(0, ver_middle, tile_size, tile_size);
    sf::FloatRect right(right_side, ver_middle, tile_size, tile_size);
    sf::FloatRect bottom(hor_middle, bottom_side, tile_size, tile_size);

    sf::FloatRect bounds = sprite->get_bounds();

    return up.intersects(bounds) || left.intersects(bounds) ||
           bottom.intersects(bounds) || right.intersects(bounds);
}

bool FireBall::intersects_with_solid_blocks() {
    sf::FloatRect bounds = sprite->get_bounds();

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
                    return true;
                }
            }
        }
    }

    return false;
}

void FireBall::ai_move(sf::Time delta_time) {
    unsigned short damage = 15;
    float speed = 1.f;

    sprite->move(direction, speed, delta_time);

    is_killed = intersects_with_solid_blocks() ||
                intersects_with_doors();

    if (is_killed) return;

    sf::FloatRect player_bounds = dungeon_ptr->player->get_bounds();
    sf::FloatRect fireball_bounds = sprite->get_bounds();

    if (!has_attacked && fireball_bounds.intersects(player_bounds)) {
        dungeon_ptr->attack_player(damage);
        has_attacked = true;
    }
}

void FireBall::set_direction(sf::Vector2f direction) {
    this->direction = direction;
}