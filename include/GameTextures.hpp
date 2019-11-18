#include "SFML/Graphics.hpp"
#pragma once

namespace GameTextures {
    sf::Texture Grass, Stone, Player;

    void init_textures() {
        Grass.loadFromFile("textures/grass00.png");
        Stone.loadFromFile("textures/rock.png");
        Player.loadFromFile("textures/runner.png");
    };
};