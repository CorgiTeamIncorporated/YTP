#include <SFML/Graphics.hpp>
// #include "debug.hpp"
#pragma once

struct MapObject {
    sf::Sprite background;
    sf::Sprite solid_part;
    sf::Sprite upper_part;

    unsigned short solid_height;

    void set_position(sf::Vector2f position);

    MapObject(sf::Sprite background, sf::Sprite solid, unsigned short height = 0);
};