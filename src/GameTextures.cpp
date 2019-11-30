#include "GameTextures.hpp"

namespace GameTextures {
    sf::Texture Button, Corgi, Logo, MenuBG, Grass, Stone, Player, Spikes, Zombie, Wall;
}

void GameTextures::init() {
    Button.loadFromFile("textures/button.png");
    Corgi.loadFromFile("textures/corgi.png");
    Logo.loadFromFile("textures/logo.png");
    MenuBG.loadFromFile("textures/menu_bg.png");
    MenuBG.setRepeated(true);
    Grass.loadFromFile("textures/grass1.png");
    Stone.loadFromFile("textures/rock.png");
    Player.loadFromFile("textures/skeleton-down-steps.png");
    Spikes.loadFromFile("textures/thorns2.png");
    Zombie.loadFromFile("textures/zombie.png");
    Wall.loadFromFile("textures/wall.png");
}
