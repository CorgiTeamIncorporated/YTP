#include "Enemies/Zombie.hpp"
#include "Scenes/Dungeon.hpp"

void Zombie::ai_move(sf::Time delta_time) {
    sf::Vector2f player_pos = dungeon_ptr->player->get_sprite().getPosition();
    sf::Vector2f enemy_pos = this->get_sprite().getPosition();

    sf::Vector2f delta = player_pos - enemy_pos;

    if (abs(delta.x) + abs(delta.y) < 10)
        dungeon_ptr->attack_player(1);

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