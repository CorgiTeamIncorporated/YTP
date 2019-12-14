#include "Scenes/AbstractScene.hpp"
#include "GameRoom.hpp"
#pragma once

class Unit;
class Zombie;
class FireBall;
class BlackHole;

class Dungeon: public AbstractScene {
private:
    sf::Sprite* health_outline;
    sf::Sprite* health_bar;

    unsigned int tile_size;
    GameRoom* current_room;
    Unit* player;

    sf::Time attack_reload_time = sf::seconds(1);
    sf::Time attack_accumulator = sf::Time::Zero;
public:
    void adjust_sizes(sf::RenderWindow& window, sf::Event event);
    void attack_player(unsigned short damage);
    void set_tile_size(unsigned int size);
    void set_room(GameRoom* room);
    void set_player(Unit* player);
    void attack_enemies();
    void check_rooms();

    void handle_event(sf::Event event);

    void preload(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    friend class Unit;
    friend class Zombie;
    friend class Spikes;
    friend class FireMan;
    friend class FireBall;
    friend class BlackHole;
};