#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include "GameManager.hpp"
#include "Enemies/Zombie.hpp"
#include <vector>

GameRoom* get_test_room(unsigned int height, unsigned int width, unsigned int tile_size) {
    GameRoom* room = new GameRoom;

    room->set_map(std::vector<std::vector<MapObject*>>(
        height, std::vector<MapObject*>(width, nullptr)
    ));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (((i == 0 || i == height - 1) && j != width / 2) ||
                ((j == 0 || j == width - 1) && i != height / 2))
                room->map[i][j] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
            else
                room->map[i][j] = new MapObject(GameSprites::Grass, sf::Sprite());

            room->map[i][j]->set_position(sf::Vector2f(tile_size * j, tile_size * i));
        }
    }

    return room;
}

void start_test_dungeon() {
    unsigned int tile_size = 100;
    unsigned int width = 11, height = 9;

    sf::RenderWindow* window = new sf::RenderWindow(
        sf::VideoMode(width * tile_size, height * tile_size), "Test window"
    );

    window->setFramerateLimit(60);

    AnimatedSprite* zombie_sprite = new AnimatedSprite(&GameSprites::Zombie, &ZombieConfig);
    AnimatedSprite* player_sprite = new AnimatedSprite(&GameSprites::Player, &SkeletonConfig);

    Zombie* zombie = new Zombie(zombie_sprite);
    zombie->set_speed(0.1);
    zombie->set_solid_height(32);
    zombie->get_sprite().setPosition(2 * tile_size, 2 * tile_size);

    Unit* player = new Unit(player_sprite);
    player->set_speed(0.5);
    player->set_solid_height(30);
    player->get_sprite().setPosition(tile_size, tile_size);

    GameRoom* left_room = get_test_room(height, width, tile_size);
    GameRoom* right_room = get_test_room(height, width, tile_size);

    left_room->right = right_room;
    right_room->left = left_room;

    Dungeon* dungeon = new Dungeon;
    dungeon->set_player(player);
    dungeon->set_room(left_room);
    dungeon->set_tile_size(tile_size);

    left_room->dungeon_ptr = dungeon;
    left_room->add_enemy(zombie);

    GameManager* manager = new GameManager(dungeon, window);
    manager->start();
}

int main() {
    GameSprites::init_sprites();
    start_test_dungeon();
}