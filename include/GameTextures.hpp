#include "SFML/Graphics.hpp"
#pragma once

namespace GameTextures {
    extern sf::Texture Grass, Stone, Player, Spikes, Zombie, Wall,
                       HealthBar, HealthOutline, Door, FireBall, FireMan,
                       SplashScreen, BlackHole;

    extern void init_textures();
};