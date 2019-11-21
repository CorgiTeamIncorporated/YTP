#include "Animation.hpp"

// See: Animation.hpp.
YDC::Animation::Animation(Object& object) :
    initialAlpha_(object.getInitialAlpha()),
    initialPosition_(object.getInitialPosition()),
    object_(object)
{
}

// See: Animation.hpp.
YDC::Animation::Animation(Object& object, const sf::Time& time) :
    initialAlpha_(object.getInitialAlpha()),
    initialPosition_(object.getInitialPosition()),
    object_(object),
    time_(time)
{
}

// See: Animation.hpp.
YDC::Animation::~Animation()
{
}

// See: Animation.hpp.
bool YDC::Animation::getDone() const
{
    // Return whether the animation has started.
    return started_;
}

// See: Animation.hpp.
void YDC::Animation::drawObject(sf::RenderWindow& window)
{
    if (!started_)
    {
        // Set the started value.
        started_ = true;

        // Reset the animation timer.
        timer_.restart();
    }
}

// See: Animation.hpp.
void YDC::Animation::resetObject()
{
    // Reset the started value.
    started_ = false;
}
