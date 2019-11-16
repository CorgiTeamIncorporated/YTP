#include "Button.hpp"

YDC::Button::Button(Content& content, const sf::String& spriteName, sf::Text& text) :
    Object(content),
    sprite_(content.getSpriteCopy(spriteName)),
    text_(text)
{
    size_ = sf::Vector2u(sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3);
}

YDC::Button::~Button()
{
}

void YDC::Button::centerText()
{
    sf::FloatRect rect = text_.getLocalBounds();
    text_.setPosition(position_.x + (size_.x - rect.width) / 2.0f, position_.y + (size_.y - rect.height) / 2.0f);
}

void YDC::Button::draw(sf::RenderWindow& window)
{
    sprite_.setPosition((sf::Vector2f)position_);
    centerText();
    sprite_.setTextureRect(sf::IntRect(0, 0, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
    if (isHovered(window))
    {
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
    }
    if (isClicked(window))
    {
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y * 2 / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
    }
    window.draw(sprite_);
    window.draw(text_);
}

bool YDC::Button::isClicked(sf::RenderWindow& window)
{
    return isHovered(window) && (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Touch::isDown(0));
}

bool YDC::Button::isHovered(sf::RenderWindow& window)
{
    return isHoveredX(window) && isHoveredY(window);
}

bool YDC::Button::isHoveredX(sf::RenderWindow& window)
{
    return (sf::Mouse::getPosition(window).x >= position_.x && sf::Mouse::getPosition(window).x <= (position_.x + size_.x));
}

bool YDC::Button::isHoveredY(sf::RenderWindow& window)
{
    return (sf::Mouse::getPosition(window).y >= position_.y && sf::Mouse::getPosition(window).y <= (position_.x + size_.y));
}

void YDC::Button::setAlpha(const sf::Uint8& alpha)
{
    sprite_.setColor(sf::Color(255, 255, 255, alpha));
    text_.setFillColor(sf::Color(text_.getFillColor().r, text_.getFillColor().g, text_.getFillColor().b, alpha));
    text_.setOutlineColor(sf::Color(text_.getOutlineColor().r, text_.getOutlineColor().g, text_.getOutlineColor().b, alpha));
}
