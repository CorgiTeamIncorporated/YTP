#include "GameTextures.hpp"

namespace GameTextures {
    sf::Texture Grass, Stone, Player, Spikes, Zombie, Wall,
                HealthBar, HealthOutline, Door, FireBall, FireMan,
                SplashScreen;
}

void GameTextures::init_textures() {
    Grass.loadFromFile("textures/grass1.png");
    Stone.loadFromFile("textures/rock.png");
    Player.loadFromFile("textures/skeleton.png");
    Spikes.loadFromFile("textures/thorns2.png");
    Zombie.loadFromFile("textures/zombie.png");
    Wall.loadFromFile("textures/wall.png");
    HealthBar.loadFromFile("textures/health.png");
    HealthOutline.loadFromFile("textures/health-outline.png");
    Door.loadFromFile("textures/door.png");
    FireBall.loadFromFile("textures/fireball.png");
    FireMan.loadFromFile("textures/fireman.png");
    SplashScreen.loadFromFile("textures/splash.png");
}