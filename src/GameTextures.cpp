#include "GameTextures.hpp"

namespace GameTextures {
    // namespace Dungeon {
        sf::Texture Button, Corgi, Logo, MenuBG, Grass, Stone, Player, Spikes, Zombie;
    // }
}

void GameTextures::init() {
    Button.loadFromFile("textures/button.png");
    Corgi.loadFromFile("textures/corgi.png");
    Logo.loadFromFile("textures/logo.png");
    MenuBG.loadFromFile("textures/menu_bg.png");
    MenuBG.setRepeated(true);
    /*Dungeon::*/Grass.loadFromFile("textures/grass1.png");
    /*Dungeon::*/Stone.loadFromFile("textures/rock.png");
    /*Dungeon::*/Player.loadFromFile("textures/skeleton-down-steps.png");
    /*Dungeon::*/Spikes.loadFromFile("textures/thorns2.png");
    /*Dungeon::*/Zombie.loadFromFile("textures/zombie.png");
}
