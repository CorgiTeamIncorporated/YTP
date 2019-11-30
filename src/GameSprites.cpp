#include "GameSprites.hpp"
#include "GameTextures.hpp"

namespace GameSprites {
    sf::Sprite Button, Corgi, Logo, MenuBG, Grass, Stone, Player, Spikes, Zombie, Wall;
}

void GameSprites::init() {
    GameTextures::init();

    Button.setTexture(GameTextures::Button);
    Corgi.setTexture(GameTextures::Corgi);
    Logo.setTexture(GameTextures::Logo);
    MenuBG.setTexture(GameTextures::MenuBG);
    Grass.setTexture(GameTextures::Grass);
    Stone.setTexture(GameTextures::Stone);
    Player.setTexture(GameTextures::Player);
    Spikes.setTexture(GameTextures::Spikes);
    Zombie.setTexture(GameTextures::Zombie);
    Wall.setTexture(GameTextures::Wall);
}
