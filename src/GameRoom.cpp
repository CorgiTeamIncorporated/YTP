#include "GameRoom.hpp"

void GameRoom::add_enemy(AbstractEnemy* enemy) {
    enemies.push_back(enemy);
    enemy->dungeon_ptr = dungeon_ptr;
}