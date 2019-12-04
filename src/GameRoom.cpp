#include "GameRoom.hpp"

void GameRoom::add_enemy(AbstractEnemy* enemy) {
    enemies.push_back(enemy);
    enemy->dungeon_ptr = dungeon_ptr;
}

void GameRoom::set_map(std::vector<std::vector<MapObject*>> map) {
    this->map = map;

    this->width = map.at(0).size();
    this->height = map.size();
}