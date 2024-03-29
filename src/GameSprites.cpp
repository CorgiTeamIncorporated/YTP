#include "GameSprites.hpp"

namespace GameSprites {
    sf::Sprite Grass, Stone, Player, Spikes, Zombie, Wall,
               HealthBar, HealthOutline, Door, FireBall, FireMan,
               SplashScreen, BlackHole;
}

void GameSprites::init_sprites() {
    GameTextures::init_textures();

    Grass.setTexture(GameTextures::Grass);
    Stone.setTexture(GameTextures::Stone);
    Player.setTexture(GameTextures::Player);
    Spikes.setTexture(GameTextures::Spikes);
    Zombie.setTexture(GameTextures::Zombie);
    Wall.setTexture(GameTextures::Wall);
    HealthBar.setTexture(GameTextures::HealthBar);
    HealthOutline.setTexture(GameTextures::HealthOutline);
    Door.setTexture(GameTextures::Door);
    FireBall.setTexture(GameTextures::FireBall);
    FireMan.setTexture(GameTextures::FireMan);
    SplashScreen.setTexture(GameTextures::SplashScreen);
    BlackHole.setTexture(GameTextures::BlackHole);
}