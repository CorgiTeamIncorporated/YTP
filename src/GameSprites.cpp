#include "GameSprites.hpp"
#include "GameTextures.hpp"

namespace GameSprites {
    // namespace Dungeon {
        sf::Sprite Button, Corgi, Logo, MenuBG, Grass, Stone, Player, Spikes, Zombie;
    // }
}

void GameSprites::init() {
    GameTextures::init();

    Button.setTexture(GameTextures::Button);
    Corgi.setTexture(GameTextures::Corgi);
    Logo.setTexture(GameTextures::Logo);
    MenuBG.setTexture(GameTextures::MenuBG);
    /*Dungeon::*/Grass.setTexture(GameTextures::/*Dungeon::*/Grass);
    /*Dungeon::*/Stone.setTexture(GameTextures::/*Dungeon::*/Stone);
    /*Dungeon::*/Player.setTexture(GameTextures::/*Dungeon::*/Player);
    /*Dungeon::*/Spikes.setTexture(GameTextures::/*Dungeon::*/Spikes);
    /*Dungeon::*/Zombie.setTexture(GameTextures::/*Dungeon::*/Zombie);
}
