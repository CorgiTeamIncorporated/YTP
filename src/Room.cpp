#include "Room.hpp"

Room::Room(unsigned short length, unsigned short height): length(length), height(height) {
    GrassTexture.loadFromFile("textures/grass00.png");
    StoneTexture.loadFromFile("textures/thorns2.png");
    PlayerTexture.loadFromFile("textures/runner.png");
    Grass.setTexture(GrassTexture);
    Stone.setTexture(StoneTexture);
    Player.setTexture(PlayerTexture);
    generateRoom();
}   

void Room::generateRoom() {
    map = std::vector<std::vector<MapObject*>>(
        height, std::vector<MapObject*>(length, nullptr)
    );

    for (int i = 1; i < height-1; i++) {
        for (int j = 1; j < length-1; j++) {
            map[i][j] = new MapObject(Grass, sf::Sprite());
        }
    }

    for(int i = 0; i < height; i++){
        map[i][0] = new MapObject(Stone, sf::Sprite());
        map[i][length-1] = new MapObject(Stone, sf::Sprite());
    }

    for(int j = 1; j < length - 1; j++){
        map[0][j] = new MapObject(Stone, sf::Sprite());
        map[height-1][j] = new MapObject(Stone, sf::Sprite());
    }
}

void Room::setPosition(int x, int y) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            map[i][j]->set_position(sf::Vector2f(x + TILE_SIZE * j, y + TILE_SIZE * i));
        }
    }
}

// void Room::generatePhysicalBlocks(){}

// void Room::generateEnemyes(){}

void Room::addRoom(unsigned short direction, Room* otherRoom){
    unsigned short middleLength = length/2;
    unsigned short middleHeight = height/2;

    switch (direction) {
    case 0:
        this->lower_room = otherRoom;
        delete map[0][middleLength-1];
        delete map[0][middleLength];
        map[0][middleLength-1] = new MapObject(Grass, sf::Sprite());
        map[0][middleLength] = new MapObject(Grass, sf::Sprite());
        break;
    case 1:
        this->right_room = otherRoom;
        delete map[middleHeight-1][length-1];
        delete map[middleHeight][length-1];
        map[middleHeight-1][length-1] = new MapObject(Grass, sf::Sprite());
        map[middleHeight][length-1] = new MapObject(Grass, sf::Sprite());
        break;
    case 2:
        this->upper_room = otherRoom;
        delete map[height-1][middleLength-1];
        delete map[height-1][middleLength];
        map[height-1][middleLength-1] = new MapObject(Grass, sf::Sprite());
        map[height-1][middleLength] = new MapObject(Grass, sf::Sprite());
        break;
    case 3:
        this->left_room = otherRoom;
        delete map[middleHeight-1][0];
        delete map[middleHeight][0];
        map[middleHeight-1][0] = new MapObject(Grass, sf::Sprite());
        map[middleHeight][0] = new MapObject(Grass, sf::Sprite());
        break;
    }
}