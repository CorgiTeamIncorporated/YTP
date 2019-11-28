#include "SFML/Graphics.hpp"
#pragma once

namespace GameTextures {
    // namespace Dungeon {
        sf::Texture Grass, Stone, Player, Spikes, Zombie;
    // }

    void init_textures() {
        /*Dungeon::*/Grass.loadFromFile("textures/grass1.png");
        /*Dungeon::*/Stone.loadFromFile("textures/rock.png");
        /*Dungeon::*/Player.loadFromFile("textures/skeleton-down-steps.png");
        /*Dungeon::*/Spikes.loadFromFile("textures/thorns2.png");
        /*Dungeon::*/Zombie.loadFromFile("textures/zombie.png");
    };
};