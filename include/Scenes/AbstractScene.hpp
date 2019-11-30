#pragma once

#include <SFML/Graphics.hpp>

class AbstractScene {
public:
    virtual void handle_event(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void preload() = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    sf::Clock timer;
};
