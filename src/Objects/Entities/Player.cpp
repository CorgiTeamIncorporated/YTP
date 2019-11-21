#include "Player.hpp"

// See: Objects/Entities/Player.hpp.
YDC::Player::Player(Content& content, const sf::String& spriteName) :
    Entity(content, spriteName)
{
}

// See: Objects/Entities/Player.hpp.
YDC::Player::~Player()
{
}

// See: Objects/Entities/Player.hpp.
void YDC::Player::handleMovement()
{
    // Reset the movement.
    resetMovement();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        // Set the backward event to active.
        eventBackwardTriggered_ = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // Set the forward event to active.
        eventForwardTriggered_ = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // Set the left event to active.
        eventLeftTriggered_ = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // Set the right event to active.
        eventRightTriggered_ = true;
    }
}

void YDC::Player::resetMovement()
{
    // Set the forward event to not active initially.
    eventForwardTriggered_ = false;

    // Set the backward event to not active initially.
    eventBackwardTriggered_ = false;

    // Set the left event to not active initially.
    eventLeftTriggered_ = false;

    // Set the right event to not active initially.
    eventRightTriggered_ = false;
}
