#include "MapObject.hpp"
#include "Enemies/AbstractEnemy.hpp"
#include <vector>
#pragma once

struct GameRoom {
    std::vector<AbstractEnemy*> enemies;
    std::vector<std::vector<MapObject*>> map;

    GameRoom* left = nullptr; GameRoom* right = nullptr;
    GameRoom* up = nullptr; GameRoom* down = nullptr;

    Dungeon* dungeon_ptr;

    unsigned short block_size;
    unsigned short width, height;

    void add_enemy(AbstractEnemy* enemy);
    void set_map(std::vector<std::vector<MapObject*>> map);
};