#include "MapObject.hpp"
#include "Enemies/AbstractEnemy.hpp"
#include <vector>
#pragma once

struct GameRoom {
    std::vector<std::vector<MapObject*>> map;
    std::vector<AbstractEnemy*> enemies;

    GameRoom* left = nullptr; GameRoom* right = nullptr;
    GameRoom* up = nullptr; GameRoom* down = nullptr;

    Dungeon* dungeon_ptr;

    unsigned short width, height;
    unsigned short block_size;

    void set_map(std::vector<std::vector<MapObject*>> map);
    void add_enemy(AbstractEnemy* enemy);
};