#include "Elements/Button.hpp"
#include "GameSprites.hpp"

Button::Button(const sf::Sprite& sprite, sf::Text& text) :
        Object(),
        sprite_(sprite),
        size_(sf::Vector2f(sprite_.getLocalBounds().width, sprite_.getLocalBounds().height / 3)),
        text_(text) {
    sprite_.setOrigin(size_.x / 2, size_.y / 2);
    text_.setOrigin(size_.x / 2, size_.y / 2);
}

Button::Button(sf::Text& text) :
        Button(GameSprites::Button, text) {}

Button::~Button() {
    delete &sprite_;
}

void Button::draw(sf::RenderWindow& window) {
    hovered_ = isHovered(window);
    clicked_ = isClicked(window);
    setSpritePosition();
    setTextPosition();
    setSpriteRectangle(window);
    window.draw(sprite_);
    window.draw(text_);
}

bool Button::getClicked() {
    return clicked_;
}

bool Button::isClicked(sf::RenderWindow& window) {
    return hovered_ && (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Touch::isDown(0));
}

bool Button::isHovered(sf::RenderWindow& window) {
    return isHoveredX(window) && isHoveredY(window);
}

bool Button::isHoveredX(sf::RenderWindow& window) {
    return (sf::Mouse::getPosition(window).x >= sprite_.getGlobalBounds().left && sf::Mouse::getPosition(window).x <= (sprite_.getGlobalBounds().left + size_.x));
}

bool Button::isHoveredY(sf::RenderWindow& window) {
    return (sf::Mouse::getPosition(window).y >= sprite_.getGlobalBounds().top && sf::Mouse::getPosition(window).y <= (sprite_.getGlobalBounds().top + size_.y));
}

void Button::setAlpha(const sf::Uint8& alpha) {
    sprite_.setColor(sf::Color(sprite_.getColor().r, sprite_.getColor().g, sprite_.getColor().b, alpha));
    text_.setFillColor(sf::Color(text_.getFillColor().r, text_.getFillColor().g, text_.getFillColor().b, alpha));
    text_.setOutlineColor(sf::Color(text_.getOutlineColor().r, text_.getOutlineColor().g, text_.getOutlineColor().b, alpha));
}

void Button::setSpritePosition() {
    sprite_.setPosition(position_ + localPosition_);
}

void Button::setSpriteRectangle(sf::RenderWindow& window) {
    if (clicked_) {
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y * 2 / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
        return;
    }

    if (hovered_) {
        sprite_.setTextureRect(sf::IntRect(0, sprite_.getTexture()->getSize().y / 3, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
        return;
    }

    sprite_.setTextureRect(sf::IntRect(0, 0, sprite_.getTexture()->getSize().x, sprite_.getTexture()->getSize().y / 3));
}

void Button::setTextPosition() {
    text_.setPosition((position_ + localPosition_).x + (size_.x - text_.getLocalBounds().width - text_.getLocalBounds().left) / 2, (position_ + localPosition_).y + (size_.y - text_.getLocalBounds().height - text_.getLocalBounds().top) / 2);
}
