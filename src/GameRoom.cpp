#include "GameRoom.hpp"
#include "GameSprites.hpp"

GameRoom::GameRoom(unsigned short width, unsigned short height, Dungeon* dungeon){
    this->width = width;
    this->height = height;
    this->dungeon_ptr = dungeon;
}

void GameRoom::add_enemy(AbstractEnemy* enemy) {
    enemies.push_back(enemy);
    enemy->dungeon_ptr = dungeon_ptr;
}

void::GameRoom::generate_map(){
    map = std::vector<std::vector<MapObject*>>(
        height, std::vector<MapObject*>(width, nullptr)
    );

    for (int i = 1; i < height-1; i++) {
        for (int j = 1; j < width-1; j++) {
            map[i][j] = new MapObject(GameSprites::Grass, sf::Sprite());
        }
    }

    for(int i = 0; i < height; i++){
        map[i][0] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
        map[i][width-1] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
    }

    for(int j = 1; j < width - 1; j++){
        map[0][j] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
        map[height-1][j] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
    }
}

void GameRoom::set_position(int x, int y) {
    int tile_width = GameSprites::Grass.getGlobalBounds().width;
    int tile_height = GameSprites::Grass.getGlobalBounds().height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j]->set_position(sf::Vector2f(x + tile_width * j, y + tile_height * i));
        }
    }
}

void GameRoom::set_position() {
    int tile_width = GameSprites::Grass.getGlobalBounds().width;
    int tile_height = GameSprites::Grass.getGlobalBounds().height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j]->set_position(sf::Vector2f(tile_width * j, tile_height * i));
        }
    }
}

void GameRoom::set_map(std::vector<std::vector<MapObject*>> map) {
    this->map = map;

    this->width = map.at(0).size();
    this->height = map.size();
}

void GameRoom::set_bottom_room(GameRoom* room) {
    this->map[this->height - 1][this->width / 2]->background.setTexture(GameTextures::Door);
    this->map[this->height - 1][this->width / 2]->solid_height = 0;
    this->down = room;
}

void GameRoom::set_right_room(GameRoom* room) {
    this->map[this->height / 2][this->width - 1]->background.setTexture(GameTextures::Door);
    this->map[this->height / 2][this->width - 1]->solid_height = 0;
    this->right = room;
}

void GameRoom::set_left_room(GameRoom* room) {
    this->map[this->height / 2][0]->background.setTexture(GameTextures::Door);
    this->map[this->height / 2][0]->solid_height = 0;
    this->left = room;
}

void GameRoom::set_top_room(GameRoom* room) {
    this->map[0][this->width / 2]->background.setTexture(GameTextures::Door);
    this->map[0][this->width / 2]->solid_height = 0;
    this->up = room;
}