#include "debug.hpp"
#include "Game.hpp"
#include "MapBuilder.hpp"
#include <vector>

int main() {
    // GameSprites::init_sprites();
    sf::Texture GrassTexture, StoneTexture, PlayerTexture;

    GrassTexture.loadFromFile("textures/grass00.png");
    StoneTexture.loadFromFile("textures/stone.png");
    PlayerTexture.loadFromFile("textures/runner.png");

    sf::Sprite Grass, Stone, Player;
    Grass.setTexture(GrassTexture);
    Stone.setTexture(StoneTexture);
    Player.setTexture(PlayerTexture);

    MapBuilder *mapBuilder = new MapBuilder(10, 20);
    mapBuilder->buildMap();
    std::vector<Room*> rooms = mapBuilder->getRoomsArray();

    AnimatedSprite* player_sprite = new AnimatedSprite(&Player, &PlayerConfig);
    Unit* player = new Unit(player_sprite);

    player->set_speed(0.5);
    player->set_solid_height(30);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Test window");

    Game* game = new Game(window, rooms, player);
    std::cout << rooms.size() << std::endl;
    game->loop();
}