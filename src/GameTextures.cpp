#include "GameTextures.hpp"

namespace GameTextures {
    sf::Texture Grass, Stone, Player, Spikes, Zombie, Wall;
}

void GameTextures::init_textures() {
    Grass.loadFromFile("textures/grass1.png");
    Stone.loadFromFile("textures/rock.png");
    Player.loadFromFile("textures/skeleton-down-steps.png");
    Spikes.loadFromFile("textures/thorns2.png");
    Zombie.loadFromFile("textures/zombie.png");
    Wall.loadFromFile("textures/wall.png");
}