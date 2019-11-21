#include "Entity.hpp"

// See: Objects/Entity.hpp.
YDC::Entity::Entity(Content& content, const sf::String& spriteName) :
    Object(content, sf::Vector2f(TILE_SIZE, TILE_SIZE)),
    size_(sf::Vector2f(sprite_.getLocalBounds().width / ENTITY_STEPS, sprite_.getLocalBounds().height / 4)),
    sprite_(content.getSpriteCopy(spriteName))
{
    // Set the sprite origin to the center.
    sprite_.setOrigin(size_.x / 2, size_.y / 2);
}

// See: Objects/Entity.hpp.
YDC::Entity::~Entity()
{
    // Delete the sprite.
    delete &sprite_;
}

// See: Objects/Entity.hpp.
void YDC::Entity::draw(sf::RenderWindow& window)
{
    // Set the entity position.
    setSpritePosition();

    // Set the sprite rectangle.
    sprite_.setTextureRect(positions_[4 * state_ + step_]);

    // Draw the sprite.
    window.draw(sprite_);
}

// See: Objects/Entity.hpp.
bool YDC::Entity::expectMove() const
{
    // Return whether any events are triggered.
    return eventForwardTriggered_ || eventBackwardTriggered_ || eventLeftTriggered_ || eventRightTriggered_;
}

// See: Objects/Entity.hpp.
sf::Uint8 YDC::Entity::fetchState() const
{
    if (eventBackwardTriggered_)
    {
        // Return the backward state.
        return 1;
    }

    if (eventLeftTriggered_)
    {
        // Return the left state.
        return 2;
    }

    if (eventRightTriggered_)
    {
        // Return the right state.
        return 3;
    }

    // Return the forward state.
    return 0;
}

// See: Objects/Entity.hpp.
sf::Vector2f YDC::Entity::getInitialPosition() const
{
    // Return the zero vector.
    return sf::Vector2f(TILE_SIZE, TILE_SIZE);
}

// See: Objects/Entity.hpp.
sf::IntRect YDC::Entity::getRect() const
{
    // Get the rectangle.
    return rect_;
}

// See: Objects/Entity.hpp.
sf::Uint8 YDC::Entity::getState() const
{
    // Get the state.
    return state_;
}

// See: Objects/Entity.hpp.
sf::Uint8 YDC::Entity::getStep() const
{
    // Get the step
    return step_;
}

// See: Objects/Entity.hpp.
void YDC::Entity::setAlpha(const sf::Uint8& alpha)
{
    // Set the sprite color.
    sprite_.setColor(sf::Color(sprite_.getColor().r, sprite_.getColor().g, sprite_.getColor().b, alpha));
}

// See: Objects/Entity.hpp.
void YDC::Entity::setSpritePosition()
{
    // Set the sprite position via the global and local positions.
    sprite_.setPosition(position_ + localPosition_);
}

// See: Objects/Entity.hpp.
void YDC::Entity::setState(const sf::Uint8& state)
{
    // Set the state.
    state_ = state;
}

// See: Objects/Entity.hpp.
void YDC::Entity::setStep(const sf::Uint8& step)
{
    // Set the step.
    step_ = step;
}
