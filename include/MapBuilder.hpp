#include "Room.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <climits>
#pragma once

class MapBuilder{
private:
    const unsigned short ROOM_LENGTH = 10;
    const unsigned short ROOM_HEIGHT = 10;

    unsigned short roomQuantity;
    Room* startRoom;
    Room* endRoom;
    std::vector<std::vector<unsigned short>> connectionsGraph;
    std::vector<Room*> rooms;

    void generateConnectionsGraph();
    void connectRooms();
    void setPosition(Room* room,  std::vector<Room*>&used, int x, int y);
     
public:
    MapBuilder(unsigned short roomQuantityMin, unsigned short roomQuantityMax);
    void buildMap();
    Room* getStartRoom();
    std::vector<Room*> getRoomsArray();
};