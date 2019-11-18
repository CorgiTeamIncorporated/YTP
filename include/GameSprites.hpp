#include "GameTextures.hpp"
#pragma once

namespace GameSprites {
    sf::Sprite Grass, Stone, Player;

    void init_sprites() {
        GameTextures::init_textures();

        Grass.setTexture(GameTextures::Grass);
        Stone.setTexture(GameTextures::Stone);
        Player.setTexture(GameTextures::Player);
    };
};