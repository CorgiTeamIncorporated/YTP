#include "Scenes/AbstractScene.hpp"
#include "GameRoom.hpp"
#pragma once

class Unit;

class Dungeon: public AbstractScene {
private:
    GameRoom* current_room;
    Unit* player;
public:
    void set_room(GameRoom* room);
    void set_player(Unit* player);
    void handle_event(sf::Event event);

    void preload();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    friend class Unit;
};