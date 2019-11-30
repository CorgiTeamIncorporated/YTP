#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class SimpleSprite : public Object {
public:
    SimpleSprite(const sf::Sprite& sprite);
    ~SimpleSprite();
    void draw(sf::RenderWindow& window);
    void setAlpha(const sf::Uint8& alpha);
private:
    sf::Sprite sprite_;
};
