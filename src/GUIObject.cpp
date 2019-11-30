#include "Elements/GUIObject.hpp"

GUIObject::GUIObject() {}

GUIObject::GUIObject(const sf::Vector2f& position):
        position_(position) {}

GUIObject::~GUIObject() {}

sf::Uint8 GUIObject::getInitialAlpha() const {
    return 255;
}

sf::Vector2f GUIObject::getInitialPosition() const {
    return sf::Vector2f(0, 0);
}

sf::Vector2f GUIObject::getLocalPosition() const {
    return localPosition_;
}

sf::Vector2f GUIObject::getPosition() const {
    return position_;
}

void GUIObject::setAlpha(const sf::Uint8& alpha) {}

void GUIObject::setLocalPosition(const sf::Vector2f& localPosition) {
    localPosition_ = localPosition;
}

void GUIObject::setPosition(const sf::Vector2f& position) {
    position_ = position;
}
