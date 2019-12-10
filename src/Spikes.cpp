#include "Enemies/Spikes.hpp"
#include "Scenes/Dungeon.hpp"
#include <iostream>

void Spikes::ai_move(sf::Time delta_time) {

    if (!is_visible){
        sf::FloatRect player_bounds = dungeon_ptr->player->get_solid_bounds();
        sf::FloatRect spikes_bounds = sprite->get_bounds();
        if (spikes_bounds.intersects(player_bounds)){
            std::cout<< "intresects" << std::endl;

            make_visible();
        }
    }
    else
    {
        dungeon_ptr->attack_player(3);
        if(timer.getElapsedTime()>=life_time)
           std::cout<< "destruction" << std::endl;
    }
    
};

void Spikes::make_visible(){
    is_visible = true;
    timer.restart();
}