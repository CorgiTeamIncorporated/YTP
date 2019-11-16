#include "Background.hpp"

YDC::Background::Background(Content& content, const sf::String& spriteName) :
    Object(content),
    sprite_(content.getSpriteCopy(spriteName))
{
}

YDC::Background::~Background()
{
}

void YDC::Background::draw(sf::RenderWindow& window)
{
    sprite_.setTextureRect(sf::IntRect(0, 0, (int)window.getSize().x, (int)window.getSize().y));
    window.draw(sprite_);
}

void YDC::Background::setAlpha(const sf::Uint8& alpha)
{
    sprite_.setColor(sf::Color(255, 255, 255, alpha));
}
