#include "Scenes/Dungeon.hpp"
#pragma once

class GameManager {
private:
    sf::RenderWindow* window;
    AbstractScene* scene;
public:
    GameManager(AbstractScene* scene, sf::RenderWindow* window);
    void start();
};