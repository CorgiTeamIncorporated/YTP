#include "Enemies/Spikes.hpp"
#include "Scenes/Dungeon.hpp"
#include <iostream>

void Spikes::ai_move(sf::Time delta_time) {
    unsigned short damage = 10;
    float radius = 20.f;

    sf::FloatRect player_bounds = dungeon_ptr->player->get_solid_bounds();
    sf::FloatRect spikes_bounds = sprite->get_bounds();

    if (!is_visible) {
        spikes_bounds.left -= radius;
        spikes_bounds.top -= radius;

        spikes_bounds.height += 2 * radius;
        spikes_bounds.width += 2 * radius;

        if (spikes_bounds.intersects(player_bounds)) {
            make_visible();
        }
    } else {
        accumulator += delta_time;

        if (accumulator >= life_time) {
            is_killed = true;
        } else if (!has_attacked) {
            if (spikes_bounds.intersects(player_bounds)) {
                dungeon_ptr->attack_player(damage);
                has_attacked = true;
            }
        }
    }
};

void Spikes::make_visible() {
    sprite->set_frame(1);
    is_visible = true;
}