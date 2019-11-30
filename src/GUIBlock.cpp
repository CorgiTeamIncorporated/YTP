#include "Elements/GUIBlock.hpp"

GUIBlock::GUIBlock(const sf::Vector2f& relativePosition):
        GUIObject(),
        relativePosition_(relativePosition) {}

GUIBlock::~GUIBlock() {}

void GUIBlock::addObject(GUIObject* instance) {
    objects_.push_back(instance);
}

const sf::Vector2f GUIBlock::calculateAbsolutePosition(sf::RenderWindow& window) {
    return sf::Vector2f(window.getSize().x / 100.0f * relativePosition_.x, window.getSize().y / 100.0f * relativePosition_.y);
}

void GUIBlock::draw(sf::RenderWindow& window) {
    for (auto& object : objects_) {
        object->setPosition(calculateAbsolutePosition(window));
        object->draw(window);
    }
}

void GUIBlock::setAlpha(const sf::Uint8& alpha) {
    for (auto& object : objects_) {
        object->setAlpha(alpha);
    }
}
