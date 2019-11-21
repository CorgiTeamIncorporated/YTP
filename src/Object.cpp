#include "Object.hpp"

// See: Object.hpp.
YDC::Object::Object(Content& content) :
    content_(content)
{
}

// See: Object.hpp.
YDC::Object::Object(Content& content, const sf::Vector2f& position) :
    content_(content),
    position_(position)
{
}

// See: Object.hpp.
YDC::Object::~Object()
{
}

// See: Object.hpp.
sf::Uint8 YDC::Object::getInitialAlpha() const
{
    // Return the fully opaque value.
    return 255;
}

// See: Object.hpp.
sf::Vector2f YDC::Object::getInitialPosition() const
{
    // Return the zero vector.
    return sf::Vector2f(0, 0);
}

// See: Object.hpp.
sf::Vector2f YDC::Object::getLocalPosition() const
{
    // Return the local position.
    return localPosition_;
}

// See: Object.hpp.
sf::Vector2f YDC::Object::getPosition() const
{
    // Return the position.
    return position_;
}

// See: Object.hpp.
void YDC::Object::setAlpha(const sf::Uint8& alpha)
{
}

// See: Object.hpp.
void YDC::Object::setLocalPosition(const sf::Vector2f& localPosition)
{
    // Set the local position value.
    localPosition_ = localPosition;
}

// See: Object.hpp.
void YDC::Object::setPosition(const sf::Vector2f& position)
{
    // Set the global position value.
    position_ = position;
}
