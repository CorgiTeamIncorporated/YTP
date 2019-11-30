#pragma once

#include <SFML/Graphics.hpp>
#include "GUIObject.hpp"

class GUISimpleSprite: public GUIObject {
public:
    GUISimpleSprite(const sf::Sprite& sprite);
    ~GUISimpleSprite();
    void draw(sf::RenderWindow& window);
    void setAlpha(const sf::Uint8& alpha);
private:
    sf::Sprite sprite_;
};
