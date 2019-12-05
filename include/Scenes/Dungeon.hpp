#include "Scenes/AbstractScene.hpp"
#include "GameRoom.hpp"
#pragma once

class Unit;
class Zombie;

class Dungeon: public AbstractScene {
private:
    sf::Texture health_outline_texture;
    sf::Texture health_bar_texture;

    sf::Sprite* health_outline;
    sf::Sprite* health_bar;

    unsigned int tile_size;
    GameRoom* current_room;
    Unit* player;
public:
    void set_room(GameRoom* room);
    void set_player(Unit* player);
    void set_tile_size(unsigned int size);
    void adjust_sizes(sf::RenderWindow& window, sf::Event event);

    void handle_event(sf::Event event);

    void preload(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    friend class Unit;
    friend class Zombie;
};