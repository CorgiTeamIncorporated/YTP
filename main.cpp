#include "Game.hpp"
#include "GameRoom.hpp"
#include <vector>

int main() {
    sf::Texture grass_texture;
    bool result = grass_texture.loadFromFile("textures/grass00.png");

    sf::Sprite* grass_sprite = new sf::Sprite;
    grass_sprite->setTexture(grass_texture);

    GameRoom* room = new GameRoom;

    room->map = std::vector<std::vector<MapObject*>>(
        10, std::vector<MapObject*>(10, nullptr)
    );

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            room->map[i][j] = new MapObject;
            room->map[i][j]->sprite = *grass_sprite;
            room->map[i][j]->is_solid = false;
            room->map[i][j]->sprite.setPosition(100 * i, 100 * j);
        }
    }

    sf::Texture player_texture;
    player_texture.loadFromFile("textures/runner.png");

    sf::Sprite* player_sprite = new sf::Sprite;
    player_sprite->setTexture(player_texture);

    AnimatedSprite* player_animated_sprite = new AnimatedSprite(player_sprite, &PlayerConfig);
    Unit* player = new Unit(player_animated_sprite);
    player->set_speed(0.5);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Test window");

    Game* game = new Game(window, room, player);
    game->loop();
}