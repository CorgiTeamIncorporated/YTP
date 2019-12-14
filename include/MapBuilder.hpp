#include "GameRoom.hpp"
#include "Scenes/Dungeon.hpp"
#include "Enemies/Zombie.hpp"
#include "Enemies/FireMan.hpp"
#include "Enemies/Spikes.hpp"
#include "Enemies/BlackHole.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <climits>
#pragma once

class MapBuilder{
private:
    const unsigned short ROOM_LENGTH = 11;
    const unsigned short ROOM_HEIGHT = 9;
    std::mt19937 mt_rand;

    unsigned short roomQuantity;
    GameRoom* startRoom;
    GameRoom* endRoom;
    Dungeon* dungeon;
    std::vector<std::vector<unsigned short>> connectionsGraph;
    std::vector<GameRoom*> rooms;

    void generateConnectionsGraph();
    void connectRooms();
    void setPosition(GameRoom* room,  std::vector<GameRoom*>&used, int x, int y);
    void setPosition(GameRoom* room,  std::vector<GameRoom*>&used);
    void addEnemies();
    std::pair<unsigned short, unsigned short> findFarestRoom();
    void findFarestRoomHelper(std::vector<std::vector<unsigned short>> &waysGraph, unsigned short i, unsigned short j, unsigned short count);
     
public:
    MapBuilder(unsigned short roomQuantityMin, unsigned short roomQuantityMax, Dungeon* dungeon);
    void buildMap();
    GameRoom* getStartRoom();
    std::vector<GameRoom*> getRoomsArray();
};