#include "MapObject.hpp"
#include "Enemies/AbstractEnemy.hpp"
#include <vector>
#pragma once

struct GameRoom {
    std::vector<AbstractEnemy*> enemies;
    std::vector<std::vector<MapObject*>> map;

    GameRoom* left; GameRoom* right;
    GameRoom* up; GameRoom* down;

    unsigned short block_size;
};