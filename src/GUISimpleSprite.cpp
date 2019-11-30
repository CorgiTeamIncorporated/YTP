#include "Elements/GUISimpleSprite.hpp"

GUISimpleSprite::GUISimpleSprite(const sf::Sprite& sprite):
        GUIObject(),
        sprite_(sprite) {
    sprite_.setOrigin(sprite_.getLocalBounds().width / 2, sprite_.getLocalBounds().height / 2);
}

GUISimpleSprite::~GUISimpleSprite() {}

void GUISimpleSprite::draw(sf::RenderWindow& window) {
    sprite_.setPosition(position_ + localPosition_);
    window.draw(sprite_);
}

void GUISimpleSprite::setAlpha(const sf::Uint8& alpha) {
    sf::Color color = sprite_.getColor();
    color.a = alpha;
    sprite_.setColor(color);
}
