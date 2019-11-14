#include "GameRoom.hpp"
#pragma once

class Unit;

class Game {
private:
    sf::RenderWindow* window;
    GameRoom* current_room;
    Unit* player;
public:
    Game(sf::RenderWindow* window, GameRoom* room, Unit* player):
      window(window), current_room(room), player(player) {
        this->player->set_game_ptr(this);
      };

   void tick(); void loop();
};