#include "Background.hpp"

// See: Objects/Background.hpp.
YDC::Background::Background(Content& content, const sf::String& spriteName) :
    Object(content),
    sprite_(content.getSpriteCopy(spriteName))
{
}

// See: Objects/Background.hpp.
YDC::Background::~Background()
{
    // Delete the sprite.
    delete &sprite_;
}

// See: Objects/Background.hpp.
void YDC::Background::draw(sf::RenderWindow& window)
{
    // Set the full window texture rectangle.
    sprite_.setTextureRect(sf::IntRect(0, 0, (int)window.getSize().x, (int)window.getSize().y));

    // Draw the sprite.
    window.draw(sprite_);
}

// See: Objects/Background.hpp.
void YDC::Background::setAlpha(const sf::Uint8& alpha)
{
    // Set the sprite color.
    sprite_.setColor(sf::Color(255, 255, 255, alpha));
}
