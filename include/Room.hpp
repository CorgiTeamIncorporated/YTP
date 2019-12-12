#include "MapObject.hpp"
#include "Enemy.hpp"
#include <vector>
#pragma once

class Room {
private:
    const int TILE_SIZE = 100;

    std::vector<Enemy*> enemies;
    std::vector<std::vector<Unit*>> mobs;
    unsigned short length;
    unsigned short height;
    sf::Texture GrassTexture, StoneTexture, PlayerTexture;
    sf::Sprite Grass, Stone, Player;

public:
    std::vector<std::vector<MapObject*>> map;
    Room *left_room = nullptr, *right_room = nullptr, *upper_room = nullptr, *lower_room = nullptr;

    Room(unsigned short length, unsigned short height);
    void generateRoom();
    // void generatePhysicalBlocks();
    // void generateEnemyes();
    void addRoom(unsigned short direction, Room* otherRoom);
    void setPosition(int x, int y);
};