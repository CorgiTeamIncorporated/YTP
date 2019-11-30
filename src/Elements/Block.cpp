#include "Elements/Block.hpp"

Block::Block(const sf::Vector2f& relativePosition) :
        Object(),
        relativePosition_(relativePosition) {}

Block::~Block() {}

void Block::addObject(Object* instance) {
    objects_.push_back(instance);
}

const sf::Vector2f Block::calculateAbsolutePosition(sf::RenderWindow& window) {
    return sf::Vector2f(window.getSize().x / 100.0f * relativePosition_.x, window.getSize().y / 100.0f * relativePosition_.y);
}

void Block::draw(sf::RenderWindow& window) {
    for (auto& object : objects_) {
        object->setPosition(calculateAbsolutePosition(window));
        object->draw(window);
    }
}

void Block::setAlpha(const sf::Uint8& alpha) {
    for (auto& object : objects_) {
        object->setAlpha(alpha);
    }
}
