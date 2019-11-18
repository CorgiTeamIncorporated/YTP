#include "debug.hpp"
#include "Game.hpp"
#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include <vector>

int main() {
    GameSprites::init_sprites();

    GameRoom* room = new GameRoom;

    room->map = std::vector<std::vector<MapObject*>>(
        10, std::vector<MapObject*>(10, nullptr)
    );

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 5 && j == 5 || i == 4 && j == 4)
                room->map[i][j] = new MapObject(GameSprites::Grass, GameSprites::Stone, 80);
            else
                room->map[i][j] = new MapObject(GameSprites::Grass, sf::Sprite());

            room->map[i][j]->set_position(sf::Vector2f(100 * i, 100 * j));
        }
    }

    AnimatedSprite* player_sprite = new AnimatedSprite(&GameSprites::Player, &PlayerConfig);
    Unit* player = new Unit(player_sprite);

    player->set_speed(0.5);
    player->set_solid_height(30);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Test window");

    Game* game = new Game(window, room, player);
    game->loop();
}