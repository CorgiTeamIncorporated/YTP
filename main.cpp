// #include "debug.hpp"
// #include "Game.hpp"
#include "Scenes/Dungeon.hpp"
#include "Scenes/MainMenu.hpp"
#include "GameFonts.hpp"
#include "GameRoom.hpp"
#include "GameManager.hpp"
#include "GameSprites.hpp"
#include "Enemies/Zombie.hpp"
#include <vector>

void start_test_room() {
    unsigned int tile_size = 100;
    unsigned int width = 10, height = 8;

    sf::RenderWindow* window = new sf::RenderWindow(
        sf::VideoMode(width * tile_size, height * tile_size), "Test window"
    );

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

    GameRoom* room = new GameRoom;

    room->map = std::vector<std::vector<MapObject*>>(
        height, std::vector<MapObject*>(width, nullptr)
    );

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                room->map[i][j] = new MapObject(GameSprites::Grass, GameSprites::Wall, 100);
            else
                room->map[i][j] = new MapObject(GameSprites::Grass, sf::Sprite());

            room->map[i][j]->set_position(sf::Vector2f(tile_size * j, tile_size * i));
        }
    }

    Dungeon* dungeon = new Dungeon;
    dungeon->set_player(player);
    dungeon->set_room(room);
    dungeon->set_tile_size(tile_size);

    room->dungeon_ptr = dungeon;
    room->add_enemy(zombie);

    MainMenu mainMenu;
    mainMenu.dungeon_ptr = dungeon;

    GameManager* manager = new GameManager(&mainMenu, window);
    mainMenu.game_manager_ptr = manager;
    manager->start();
}

int main(int argc, char** argv) {
    GameFonts::init();
    GameSprites::init();
    start_test_room();
    return EXIT_SUCCESS;
 }
