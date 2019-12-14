#include "SFML/Graphics.hpp"
#pragma once

class GameManager;

class AbstractScene {
protected:
    GameManager* manager;
public:
    virtual void preload(sf::RenderWindow& window) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    sf::Clock timer;

    friend class GameManager;
};