#include "MapObject.hpp"

void MapObject::set_position(sf::Vector2f position) {
    // Sets the background sprite left upper corner position on the map
    // Sets the solid sprite position that the bottoms
    // of both sprites are on the same height
    background.setPosition(position);
    solid_part.setPosition(position);
    sf::FloatRect upper_bounds = upper_part.getGlobalBounds();
    unsigned short upper_y = position.y - upper_bounds.height,
                   upper_x = position.x;
    upper_part.setPosition(sf::Vector2f(upper_x, upper_y));
};

MapObject::MapObject(sf::Sprite background, sf::Sprite solid, unsigned short height = 0) {
    this->background = background;
    solid_part = upper_part = solid;
    solid_height = height;
    sf::FloatRect solid_bounds = solid.getGlobalBounds();
    sf::FloatRect background_bounds = background.getGlobalBounds();

    unsigned short upper_height = solid_bounds.height - height;
    unsigned short width = background_bounds.width;

    upper_part.setTextureRect(sf::IntRect(0, 0, width, upper_height));
    solid_part.setTextureRect(sf::IntRect(0, upper_height, width, height));

    set_position(sf::Vector2f(0, 0));
};