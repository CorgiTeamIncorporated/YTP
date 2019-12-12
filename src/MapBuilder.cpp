#include "MapBuilder.hpp"

MapBuilder::MapBuilder(unsigned short roomQuantityMin, unsigned short roomQuantityMax){
    roomQuantity = std::rand() % (roomQuantityMax - roomQuantityMin) + roomQuantityMin;
    startRoom = new Room(ROOM_LENGTH, ROOM_HEIGHT);
}

void MapBuilder::generateConnectionsGraph(){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    unsigned short backboneRoomsQuantity = roomQuantity*60/100;
    unsigned short extraRoomsQuantity = roomQuantity - backboneRoomsQuantity;
    connectionsGraph = std::vector<std::vector<unsigned short>>(
        roomQuantity*2+1, std::vector<unsigned short>(roomQuantity*2+1, USHRT_MAX)
    );
    unsigned short x = roomQuantity;
    unsigned short y = roomQuantity;
    unsigned short roomNumber = 0;
    connectionsGraph[y][x] = roomNumber;
    roomNumber++;

    for(int i = 0; i < backboneRoomsQuantity; i++){
        unsigned short direction = mt_rand()%4;

        switch (direction) {
        case 0: // add upper room
            if(connectionsGraph[y+1][x] != USHRT_MAX){
                i--;
                continue;
            }
            y++;
            break;
        
        case 1: // add right room
            if(connectionsGraph[y][x+1] != USHRT_MAX){
                i--;
                continue;
            }
            x++;
            break;  

        case 2: // add lower room
            if(connectionsGraph[y-1][x] != USHRT_MAX){
                i--;
                continue;
            }
            y--;
            break;

        case 3: // add left room
            if(connectionsGraph[y][x-1] != USHRT_MAX){
                i--;
                continue;
            }
            x--;
            break;
        }
        connectionsGraph[y][x] = roomNumber;
        roomNumber++;
    }

    for (int i = 0; i < extraRoomsQuantity; i++){
        unsigned short direction;
        unsigned short nextRoom;
        bool successful = false;

        while (!successful) {        
            nextRoom  = mt_rand() % backboneRoomsQuantity + 1;
            direction = mt_rand()%4;

            for(int xi = 0; xi < roomQuantity*2+1; xi++){
                for(int yj = 0; yj < roomQuantity*2+1; yj++){
                    if(connectionsGraph[yj][xi] == nextRoom){
                        x = xi; y = yj;
                    }
                }
            }

            switch (direction) {
            case 0:
                if(connectionsGraph[y+1][x] != USHRT_MAX){
                    continue;
                }
                y++;
                break;
            
            case 1:
                if(connectionsGraph[y][x+1] != USHRT_MAX){
                    continue;
                }
                x++;
                break;

            case 2:
                if(connectionsGraph[y-1][x] != USHRT_MAX){
                    continue;
                }
                y--;
                break;

            case 3:
                if(connectionsGraph[y][x--] != USHRT_MAX){
                    continue;
                }
                x--;
                break;
            }
            
            connectionsGraph[y][x] = roomNumber;
            roomNumber++;

            backboneRoomsQuantity++;
            successful = true;
        }
    }

    for(int i = 0;i<2*roomQuantity+1;i++){
        for(int j =0; j<2*roomQuantity+1;j++){
            if(connectionsGraph[i][j] < 10){
                std::cout << connectionsGraph[i][j] << "  " ; 
            }

            else if(connectionsGraph[i][j] < 100){
                std::cout << connectionsGraph[i][j] << " " ; 
            }
            else if(connectionsGraph[i][j] == USHRT_MAX){
                std::cout<< "-  " ; 
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MapBuilder::connectRooms(){
    rooms = std::vector<Room*>(roomQuantity+1, nullptr);
    rooms[0] = startRoom;
    
    for(int i = 1; i <= roomQuantity; i++){
        rooms[i] = new Room(ROOM_LENGTH, ROOM_HEIGHT);
    }

    if(connectionsGraph[roomQuantity+1][roomQuantity] != USHRT_MAX){
        startRoom->addRoom(2, rooms[connectionsGraph[roomQuantity+1][roomQuantity]]); 
        rooms[connectionsGraph[roomQuantity+1][roomQuantity]]->addRoom(0, startRoom);
    }
    else if(connectionsGraph[roomQuantity][roomQuantity+1] != USHRT_MAX){
        startRoom->addRoom(1, rooms[connectionsGraph[roomQuantity][roomQuantity+1]]);
        rooms[connectionsGraph[roomQuantity][roomQuantity+1]]->addRoom(3, startRoom); 
    }
    else if(connectionsGraph[roomQuantity-1][roomQuantity] != USHRT_MAX){
        startRoom->addRoom(0, rooms[connectionsGraph[roomQuantity-1][roomQuantity]]);
        rooms[connectionsGraph[roomQuantity-1][roomQuantity]]->addRoom(2, startRoom); 
    }
    else if(connectionsGraph[roomQuantity][roomQuantity-1] != USHRT_MAX) {
        startRoom->addRoom(3, rooms[connectionsGraph[roomQuantity][roomQuantity-1]]);
        rooms[connectionsGraph[roomQuantity][roomQuantity-1]]->addRoom(1, startRoom); 
    }

    for(int x = 0; x < roomQuantity*2+1; x++){
        for(int y = 0; y < roomQuantity*2+1; y++){
            if(x==roomQuantity &&  y==roomQuantity){
                continue;
            }
            if(connectionsGraph[y][x]!=USHRT_MAX){
                // std::cout << connectionsGraph[y][x] << std::endl;
                if(y < roomQuantity*2 && connectionsGraph[y+1][x] != USHRT_MAX && connectionsGraph[y+1][x] != 0){
                    rooms[connectionsGraph[y][x]]->addRoom(2, rooms[connectionsGraph[y+1][x]]); 
                }
                if(x < roomQuantity*2 && connectionsGraph[y][x+1] != USHRT_MAX && connectionsGraph[y][x+1] != 0){
                    rooms[connectionsGraph[y][x]]->addRoom(1, rooms[connectionsGraph[y][x+1]]); 
                }
                if(y > 0 && connectionsGraph[y-1][x] != USHRT_MAX && connectionsGraph[y-1][x] != 0){
                    rooms[connectionsGraph[y][x]]->addRoom(0, rooms[connectionsGraph[y-1][x]]); 
                }
                if(x > 0 && connectionsGraph[y][x-1] != USHRT_MAX && connectionsGraph[y][x-1] != 0) {
                    rooms[connectionsGraph[y][x]]->addRoom(3, rooms[connectionsGraph[y][x-1]]); 
                }
            }
        }
    }
}

void MapBuilder::setPosition(Room* room, std::vector<Room*> &used, int x = 0, int y = 0){
    room->setPosition(x, y);
    used.push_back(room);
    if(room->upper_room != nullptr && std::find(used.begin(), used.end(), room->upper_room) == used.end()){
        setPosition(room->upper_room, used, x, y+ROOM_HEIGHT*100);
    }
    if(room->right_room!= nullptr && std::find(used.begin(), used.end(), room->right_room) == used.end()){
        setPosition(room->right_room, used, x+ROOM_LENGTH*100, y);
    }
    if(room->lower_room != nullptr && std::find(used.begin(), used.end(), room->lower_room) == used.end()){
        setPosition(room->lower_room, used, x, y-ROOM_HEIGHT*100);
    }
    if(room->left_room != nullptr && std::find(used.begin(), used.end(), room->left_room) == used.end()){
        setPosition(room->left_room, used, x-ROOM_LENGTH*100, y);
    }
}

void MapBuilder::buildMap() {
    this->generateConnectionsGraph();
    this->connectRooms();
    std::vector<Room*>used;
    this->setPosition(startRoom, used);
}

Room* MapBuilder::getStartRoom() {
    return startRoom;
}

std::vector<Room*> MapBuilder::getRoomsArray(){
    return rooms;
}
