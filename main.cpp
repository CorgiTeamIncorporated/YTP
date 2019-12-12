#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include "GameManager.hpp"
#include "Enemies/Zombie.hpp"
#include "Enemies/Spikes.hpp"
#include <vector>

GameRoom* get_test_room(unsigned int height, unsigned int width, unsigned int tile_size) {
    GameRoom* room = new GameRoom;

    room->set_map(std::vector<std::vector<MapObject*>>(
        height, std::vector<MapObject*>(width, nullptr)
    ));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                if (((i == 0 || i == height - 1) && j == width / 2) ||
                    ((j == 0 || j == width - 1) && i == height / 2)) {
                    room->map[i][j] = new MapObject(GameSprites::Grass, GameSprites::Door, 100);
                } else {
                    room->map[i][j] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
                }
            } else {
                room->map[i][j] = new MapObject(GameSprites::Grass, sf::Sprite());
            }

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

    AnimatedSprite* zombie_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::Zombie), &ZombieConfig);
    
    AnimatedSprite* second_zombie_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::Zombie), &ZombieConfig);

    AnimatedSprite* player_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::Player), &SkeletonConfig);

    AnimatedSprite* spikes_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::Spikes), &SpikesConfig);

    Zombie* zombie = new Zombie(zombie_sprite);
    zombie->set_speed(0.2);
    zombie->set_solid_height(32);
    zombie->get_sprite().setPosition(2 * tile_size, 2 * tile_size);

    Zombie* second_zombie = new Zombie(second_zombie_sprite);
    second_zombie->set_speed(0.2);
    second_zombie->set_solid_height(32);
    second_zombie->get_sprite().setPosition(5 * tile_size, 5 * tile_size);

    Unit* player = new Unit(player_sprite);
    player->set_speed(0.5);
    player->set_solid_height(30);
    player->get_sprite().setPosition(tile_size, tile_size);

    Spikes* spikes = new Spikes(spikes_sprite);
    spikes->get_sprite().setPosition(2 * tile_size, 2 * tile_size);

    GameRoom* main_room = get_test_room(height, width, tile_size);
    GameRoom* right_room = get_test_room(height, width, tile_size);
    GameRoom* bottom_room = get_test_room(height, width, tile_size);

    main_room->set_right_room(right_room);
    right_room->set_left_room(main_room);
    main_room->set_bottom_room(bottom_room);
    bottom_room->set_top_room(main_room);

    Dungeon* dungeon = new Dungeon;
    dungeon->set_player(player);
    dungeon->set_room(main_room);
    dungeon->set_tile_size(tile_size);

    main_room->dungeon_ptr = dungeon;
    main_room->add_enemy(zombie);
    main_room->add_enemy(second_zombie);

    right_room->dungeon_ptr = dungeon;
    right_room->add_enemy(spikes);

    bottom_room->dungeon_ptr = dungeon;

    GameManager* manager = new GameManager(dungeon, window);
    manager->start();
}

int main() {
    GameSprites::init_sprites();
    start_test_dungeon();
}