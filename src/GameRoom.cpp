#include "GameRoom.hpp"
#include "GameSprites.hpp"

void GameRoom::add_enemy(AbstractEnemy* enemy) {
    enemies.push_back(enemy);
    enemy->dungeon_ptr = dungeon_ptr;
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