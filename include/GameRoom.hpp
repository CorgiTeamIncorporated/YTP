#include "MapObject.hpp"
#include "Enemy.hpp"
#include <vector>
#pragma once

struct GameRoom {
    std::vector<Enemy*> enemies;
    std::vector<std::vector<MapObject*>> map;

    GameRoom* left; GameRoom* right;
    GameRoom* up; GameRoom* down;

    unsigned short block_size;
};