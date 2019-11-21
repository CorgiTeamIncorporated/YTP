#include "Block.hpp"

// See: Objects/Block.hpp.
YDC::Block::Block(Content& content, const sf::Vector2f& relativePosition) :
    Object(content),
    relativePosition_(relativePosition)
{
}

// See: Objects/Block.hpp.
YDC::Block::~Block()
{
}

// See: Objects/Block.hpp.
void YDC::Block::addObject(Object* instance)
{
    // Push the object in the list.
    objects_.push_back(instance);
}

// See: Objects/Block.hpp.
const sf::Vector2f YDC::Block::calculateAbsolutePosition(sf::RenderWindow& window)
{
    // Convert the percents to the position.
    return sf::Vector2f(window.getSize().x / 100.0f * relativePosition_.x, window.getSize().y / 100.0f * relativePosition_.y);
}

// See: Objects/Block.hpp.
void YDC::Block::draw(sf::RenderWindow& window)
{
    for (auto& object : objects_)
    {
        // Set the global position of the object.
        object->setPosition(calculateAbsolutePosition(window));

        // Draw the object.
        object->draw(window);
    }
}

// See: Objects/Block.hpp.
void YDC::Block::setAlpha(const sf::Uint8& alpha)
{
    for (auto& object : objects_)
    {
        // Set the alpha value of the object.
        object->setAlpha(alpha);
    }
}
