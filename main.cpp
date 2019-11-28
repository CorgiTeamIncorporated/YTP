// #include "debug.hpp"
// #include "Game.hpp"
#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include "GameManager.hpp"
#include "Enemies/Zombie.hpp"
#include <vector>

int main() {
    GameSprites::init_sprites();

    GameRoom* room = new GameRoom;

    room->map = std::vector<std::vector<MapObject*>>(
        10, std::vector<MapObject*>(10, nullptr)
    );

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(i == 3 && j == 3)
                room->map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, GameSprites::/*Dungeon::*/Spikes, 100);
            else if (i == 5 && j == 5 || i == 4 && j == 4)
                room->map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, GameSprites::/*Dungeon::*/Stone, 80);
            else
                room->map[i][j] = new MapObject(GameSprites::/*Dungeon::*/Grass, sf::Sprite());

            room->map[i][j]->set_position(sf::Vector2f(100 * i, 100 * j));
        }
    }

    AnimatedSprite* zombie_sprite = new AnimatedSprite(&GameSprites::Zombie, &ZombieConfig);
    Zombie* zombie = new Zombie(zombie_sprite);

    AnimatedSprite* player_sprite = new AnimatedSprite(&GameSprites::/*Dungeon::*/Player, &SkeletonConfig);
    Unit* player = new Unit(player_sprite);

    player->set_speed(0.5);
    player->set_solid_height(30);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Test window");

    Dungeon* dungeon = new Dungeon;
    dungeon->set_player(player);
    dungeon->set_room(room);
    dungeon->set_tile_size(100);

    room->dungeon_ptr = dungeon;
    room->add_enemy(zombie);

    zombie->set_speed(0.1);
    zombie->set_solid_height(32);

    GameManager* manager = new GameManager(dungeon, window);
    manager->start();
}