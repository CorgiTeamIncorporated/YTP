#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Button : public Object
{
public:
    Button(const sf::Sprite& sprite, sf::Text& text);
    Button(sf::Text& text);
    ~Button();
    void draw(sf::RenderWindow& window);
    bool getClicked();
    void setAlpha(const sf::Uint8& alpha);

private:
    bool clicked_ = false;
    bool hovered_ = false;
    sf::Sprite sprite_;
    sf::Vector2f size_;
    sf::Text text_;
    bool isClicked(sf::RenderWindow& window);
    bool isHovered(sf::RenderWindow& window);
    bool isHoveredX(sf::RenderWindow& window);
    bool isHoveredY(sf::RenderWindow& window);
    void setSpritePosition();
    void setSpriteRectangle(sf::RenderWindow& window);
    void setTextPosition();
};
