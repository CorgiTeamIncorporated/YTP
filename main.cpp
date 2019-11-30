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

int main() {
    GameFonts::init();
    GameSprites::init();

    GameRoom room;

    room.map = std::vector<std::vector<MapObject*>>(10, std::vector<MapObject*>(10, nullptr));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(i == 3 && j == 3)
                room.map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, GameSprites::/*Dungeon::*/Spikes, 100);
            else if (i == 5 && j == 5 || i == 4 && j == 4)
                room.map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, GameSprites::/*Dungeon::*/Stone, 80);
            else
                room.map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, sf::Sprite());

            room.map[i][j]->set_position(sf::Vector2f(100 * i, 100 * j));
        }
    }

    AnimatedSprite zombie_sprite(&GameSprites::Zombie, &ZombieConfig);
    Zombie zombie(&zombie_sprite);

    zombie.set_speed(0.1);
    zombie.set_solid_height(32);

    AnimatedSprite player_sprite(&GameSprites::/*Dungeon::*/Player, &SkeletonConfig);
    Unit player(&player_sprite);

    player.set_speed(0.5);
    player.set_solid_height(30);

    Dungeon dungeon;

    dungeon.set_player(&player);
    dungeon.set_room(&room);
    dungeon.set_tile_size(100);

    room.dungeon_ptr = &dungeon;
    room.add_enemy(&zombie);

    MainMenu mainMenu;

    mainMenu.dungeon_ptr = &dungeon;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Test window");
    GameManager manager(&mainMenu, &window);

    mainMenu.game_manager_ptr = &manager;

    manager.start();

    return EXIT_SUCCESS;
}
