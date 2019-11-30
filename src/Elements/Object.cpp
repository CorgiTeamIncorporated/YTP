#include "Elements/Object.hpp"

Object::Object() {}

Object::Object(const sf::Vector2f& position) :
        position_(position) {}

Object::~Object() {}

sf::Uint8 Object::getInitialAlpha() const {
    return 255;
}

sf::Vector2f Object::getInitialPosition() const {
    return sf::Vector2f(0, 0);
}

sf::Vector2f Object::getLocalPosition() const {
    return localPosition_;
}

sf::Vector2f Object::getPosition() const {
    return position_;
}

void Object::setAlpha(const sf::Uint8& alpha) {}

void Object::setLocalPosition(const sf::Vector2f& localPosition) {
    localPosition_ = localPosition;
}

void Object::setPosition(const sf::Vector2f& position) {
    position_ = position;
}
