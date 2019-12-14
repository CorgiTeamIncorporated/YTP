#include "Enemies/BlackHole.hpp"
#include "Scenes/Dungeon.hpp"

void BlackHole::ai_move(sf::Time delta_time) {
    unsigned short damage = 666;
    
    float hor_middle = (dungeon_ptr->current_room->width / 2) * dungeon_ptr->tile_size;
    float ver_middle = (dungeon_ptr->current_room->height / 2) * dungeon_ptr->tile_size;
    sf::FloatRect solid_bounds = dungeon_ptr->player->get_solid_bounds();
    sf::FloatRect blackHole_bounds(hor_middle, ver_middle, dungeon_ptr->tile_size, dungeon_ptr->tile_size);

    if (blackHole_bounds.intersects(solid_bounds)) {
        dungeon_ptr->attack_player(damage);
    }
}