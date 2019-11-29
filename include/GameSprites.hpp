#include "GameTextures.hpp"
#pragma once

namespace GameSprites {
    sf::Sprite Grass, Stone, Player, Spikes, Zombie, Wall;

    void init_sprites() {
        GameTextures::init_textures();

        Grass.setTexture(GameTextures::Grass);
        Stone.setTexture(GameTextures::Stone);
        Player.setTexture(GameTextures::Player);
        Spikes.setTexture(GameTextures::Spikes);
        Zombie.setTexture(GameTextures::Zombie);
        Wall.setTexture(GameTextures::Wall);
    };
};