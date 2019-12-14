#include "Enemies/Zombie.hpp"
#include "Scenes/Dungeon.hpp"

void Zombie::ai_move(sf::Time delta_time) {
    if (health <= 0) {
        is_killed = true; return;
    }

    unsigned short damage = 5;
    float radius = 10.f;

    attack_accumulator += delta_time;

    sf::Vector2f player_pos = dungeon_ptr->player->get_sprite().getPosition();
    sf::Vector2f enemy_pos = this->get_sprite().getPosition();

    sf::Vector2f delta = player_pos - enemy_pos;

    if (abs(delta.x) + abs(delta.y) < radius &&
        attack_accumulator >= attack_reload_time) {
        dungeon_ptr->attack_player(damage);
        attack_accumulator = sf::Time::Zero;
    }

    if (abs(delta.x) > abs(delta.y)) {
        if (delta.x < 0)
            this->direction = Directions::Left;
        else
            this->direction = Directions::Right;
    } else {
        if (delta.y < 0)
            this->direction = Directions::Up;
        else
            this->direction = Directions::Down;
    }

    this->move(delta_time);
}