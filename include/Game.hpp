#include "Room.hpp"
#include <vector>
#pragma once

class Unit;

class Game {
private:
    sf::RenderWindow* window;
    sf::View view;
    std::vector<Room*> rooms;
    Unit* player;
public:
    Game(sf::RenderWindow* window, std::vector<Room*> &rooms, Unit* player):
      window(window), rooms(rooms), player(player) {
        this->player->set_game_ptr(this);
      };

   void tick(); void loop();
   void draw_background();
   void complete_drawing();

   friend class Unit;
};