#include "GameTextures.hpp"
#pragma once

namespace GameSprites {
    // namespace Dungeon {
        sf::Sprite Grass, Stone, Player, Spikes, Zombie;
    // };

    void init_sprites() {
        GameTextures::init_textures();

        /*Dungeon::*/Grass.setTexture(GameTextures::/*Dungeon::*/Grass);
        /*Dungeon::*/Stone.setTexture(GameTextures::/*Dungeon::*/Stone);
        /*Dungeon::*/Player.setTexture(GameTextures::/*Dungeon::*/Player);
        /*Dungeon::*/Spikes.setTexture(GameTextures::/*Dungeon::*/Spikes);
        /*Dungeon::*/Zombie.setTexture(GameTextures::/*Dungeon::*/Zombie);
    };
};