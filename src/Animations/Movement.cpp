#include "../Config.hpp"
#include "Movement.hpp"

// See: Animations/Movement.hpp.
YDC::Movement::Movement(Entity& entity) :
    Animation(entity),
    entity_(entity)
{
}

// See: Animations/Movement.hpp.
YDC::Movement::Movement(Entity& entity, const sf::Time& time) :
    Animation(entity, time),
    entity_(entity)
{
}

// See: Animations/Movement.hpp.
YDC::Movement::~Movement()
{
}

// See: Animations/Movement.hpp.
void YDC::Movement::drawObject(sf::RenderWindow& window)
{
    // Start the animation if necessary.
    Animation::drawObject(window);

    // Handle the movement.
    entity_.handleMovement();

    if (entity_.getState() == entity_.fetchState())
    {
        // Reset the movement - same direction.
        entity_.resetMovement();
    }

    // Set the current position value.
    entity_.setLocalPosition(getCurrentPosition());

    // Set the current step.
    entity_.setStep(getCurrentStep());

    // Draw the entity.
    entity_.draw(window);
}

// See: Animations/Movement.hpp.
sf::Vector2f YDC::Movement::getCurrentPosition() const
{
    switch (entity_.getState())
    {
    case 0:
        // Return the increased in back position.
        return sf::Vector2f(0, getCurrentPositionDelta());
    case 1:
        // Return the increased in front position.
        return sf::Vector2f(0, -getCurrentPositionDelta());
    case 2:
        // Return the increased in left position.
        return sf::Vector2f(-getCurrentPositionDelta(), 0);
    }

    // Return the increased in right position.
    return sf::Vector2f(getCurrentPositionDelta(), 0);
}

// See: Animations/Movement.hpp.
float YDC::Movement::getCurrentPositionDelta() const
{
    // Return the alpha depending on the timer value, so it can contain an error.
    return ENTITY_STEP * (timer_.getElapsedTime() / time_);
}

// See: Animations/Movement.hpp.
sf::Uint8 YDC::Movement::getCurrentStep() const
{
    // Return the alpha depending on the timer value, so it can contain an error.
    return ENTITY_STEPS * (timer_.getElapsedTime() / time_);
}

// See: Animations/Movement.hpp.
bool YDC::Movement::getDone() const
{
    // Return that the animation is done when the time exceeds the expected time.
    return Animation::getDone() && (timer_.getElapsedTime() >= time_ || entity_.expectMove());
}

// See: Animations/Movement.hpp.
void YDC::Movement::resetObject()
{
    // Reset the animation itself.
    Animation::resetObject();

    // Set the global position.
    entity_.setPosition(entity_.getPosition() + entity_.getLocalPosition());

    // Reset the local position.
    entity_.setLocalPosition(sf::Vector2f(0, 0));

    // Reset the step.
    entity_.setStep(0);
}
