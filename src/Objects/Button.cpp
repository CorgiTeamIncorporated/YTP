#include "Button.hpp"

// See: Objects/Button.hpp.
YDC::Button::Button(Content& content, const sf::String& spriteName, sf::Text& text) :
    Object(content),
    sprite_(content.getSpriteCopy(spriteName)),
    size_(sf::Vector2f(sprite_.getLocalBounds().width, sprite_.getLocalBounds().height / 3)),
    text_(text)
{
    // Set the sprite origin to the center.
    sprite_.setOrigin(size_.x / 2, size_.y / 2);

    // Set the text origin to the center.
    text_.setOrigin(size_.x / 2, size_.y / 2);
}

// See: Objects/Button.hpp.
YDC::Button::Button(Content& content, sf::Text& text) :
    Button(content, "Button", text)
{
}

// See: Objects/Button.hpp.
YDC::Button::~Button()
{
    // Delete the sprite.
    delete &sprite_;
}

// See: Objects/Button.hpp.
void YDC::Button::draw(sf::RenderWindow& window)
{
    // Set whether the button is hovered.
    hovered_ = isHovered(window);

    // Set whether the button is clicked.
    clicked_ = isClicked(window);

    // Set the button sprite position.
    setSpritePosition();

    // Set the button text position.
    setTextPosition();

    // Set the sprite rectangle.
    setSpriteRectangle(window);

    // Draw the sprite.
    window.draw(sprite_);

    // Draw the text.
    window.draw(text_);
}

// See: Objects/Button.hpp.
bool YDC::Button::getClicked()
{
    // Return whether the button is clicked.
    return clicked_;
}

// See: Objects/Button.hpp.
bool YDC::Button::isClicked(sf::RenderWindow& window)
{
    // Return whether the button is hovered and the screen is clicked.
    return hovered_ && (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Touch::isDown(0));
}

// See: Objects/Button.hpp.
bool YDC::Button::isHovered(sf::RenderWindow& window)
{
    // Return whether the mouse is within the button rectangle on both x and y axis.
    return isHoveredX(window) && isHoveredY(window);
}

// See: Objects/Button.hpp.
bool YDC::Button::isHoveredX(sf::RenderWindow& window)
{
    // Return whether the mouse is within the button rectangle on the x axis.
    return (sf::Mouse::getPosition(window).x >= sprite_.getGlobalBounds().left && sf::Mouse::getPosition(window).x <= (sprite_.getGlobalBounds().left + size_.x));
}

// See: Objects/Button.hpp.
bool YDC::Button::isHoveredY(sf::RenderWindow& window)
{
    // Return whether the mouse is within the button rectangle on the xy axis.
    return (sf::Mouse::getPosition(window).y >= sprite_.getGlobalBounds().top && sf::Mouse::getPosition(window).y <= (sprite_.getGlobalBounds().top + size_.y));
}

// See: Objects/Button.hpp.
void YDC::Button::setAlpha(const sf::Uint8& alpha)
{
    // Set the alpha color of the sprite.
    sprite_.setColor(sf::Color(sprite_.getColor().r, sprite_.getColor().g, sprite_.getColor().b, alpha));

    // Set the fill alpha color of the text.
    text_.setFillColor(sf::Color(text_.getFillColor().r, text_.getFillColor().g, text_.getFillColor().b, alpha));

    // Set the outline alpha color of the text.
    text_.setOutlineColor(sf::Color(text_.getOutlineColor().r, text_.getOutlineColor().g, text_.getOutlineColor().b, alpha));
}

// See: Objects/Button.hpp.
void YDC::Button::setSpritePosition()
{
    // Set the sprite position via the global and local positions.
    sprite_.setPosition(position_ + localPosition_);
}

// See: Objects/Button.hpp.
void YDC::Button::setSpriteRectangle(sf::RenderWindow& window)
{
    if (clicked_)
    {
        // Set the clicked button sprite.
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y * 2 / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));

        // The sprite is set; no need to continue.
        return;
    }

    if (hovered_)
    {
        // Set the hovered button sprite.
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));

        // The sprite is set; no need to continue.
        return;
    }

    // Set the default button sprite.
    sprite_.setTextureRect(sf::IntRect(0, 0, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
}

// See: Objects/Button.hpp.
void YDC::Button::setTextPosition()
{
    // Center the text according to the button rectangle.
    text_.setPosition((position_ + localPosition_).x + (size_.x - text_.getLocalBounds().width - text_.getLocalBounds().left) / 2, (position_ + localPosition_).y + (size_.y - text_.getLocalBounds().height - text_.getLocalBounds().top) / 2);
}
