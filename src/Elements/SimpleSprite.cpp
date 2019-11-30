#include "Elements/SimpleSprite.hpp"

SimpleSprite::SimpleSprite(const sf::Sprite& sprite) :
        Object(),
        sprite_(sprite) {
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2, sprite_.getLocalBounds().height / 2);
}

SimpleSprite::~SimpleSprite() {}

void SimpleSprite::draw(sf::RenderWindow& window) {
    sprite_.setPosition(position_ + localPosition_);
    window.draw(sprite_);
}

void SimpleSprite::setAlpha(const sf::Uint8& alpha) {
    sf::Color color = sprite_.getColor();
    color.a = alpha;
    sprite_.setColor(color);
}
