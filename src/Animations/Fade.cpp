#include "Fade.hpp"

// See: Animations/Fade.hpp.
YDC::Fade::Fade(Object& object) :
    Animation(object)
{
}

// See: Animations/Fade.hpp.
YDC::Fade::Fade(Object& object, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha) :
    Animation(object),
    endAlpha_(endAlpha),
    startAlpha_(startAlpha)
{
}

// See: Animations/Fade.hpp.
YDC::Fade::Fade(Object& object, const sf::Time& time) :
    Animation(object, time)
{
}

// See: Animations/Fade.hpp.
YDC::Fade::Fade(Object& object, const sf::Time& time, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha) :
    Animation(object, time),
    endAlpha_(endAlpha),
    startAlpha_(startAlpha)
{
}

// See: Animations/Fade.hpp.
YDC::Fade::~Fade()
{
}

// See: Animations/Fade.hpp.
void YDC::Fade::drawObject(sf::RenderWindow& window)
{
    // Start the animation if necessary.
    Animation::drawObject(window);

    // Set the object alpha.
    object_.setAlpha(getCurrentAlpha());

    // Draw the object.
    object_.draw(window);
}

// See: Animations/Fade.hpp.
sf::Uint8 YDC::Fade::getCurrentAlpha() const
{
    // Get the alpha value with an error.
    sf::Int16 alpha = getCurrentAlphaWithError();

    if (startAlpha_ < endAlpha_)
    {
        if (alpha > endAlpha_)
        {
            // Return the end alpha as the closest one.
            return endAlpha_;
        }
        else if (alpha < startAlpha_)
        {
            // Return the start alpha as the closest one.
            return startAlpha_;
        }
    }
    else
    {
        if (alpha < endAlpha_)
        {
            // Return the end alpha as the closest one.
            return endAlpha_;
        }
        else if (alpha > startAlpha_)
        {
            // Return the start alpha as the closest one.
            return startAlpha_;
        }
    }

    // Return alpha as there is no error in it.
    return alpha;
}

// See: Animations/Fade.hpp.
sf::Int16 YDC::Fade::getCurrentAlphaWithError() const
{
    // Return the alpha depending on the timer value, so it can contain an error.
    return startAlpha_ + (endAlpha_ - startAlpha_) * (timer_.getElapsedTime() / time_);
}

// See: Animations/Fade.hpp.
bool YDC::Fade::getDone() const
{
    // Return that the animation is done when the time exceeds the expected time.
    return Animation::getDone() && timer_.getElapsedTime() >= time_;
}

// See: Animations/Fade.hpp.
void YDC::Fade::resetObject()
{
    // Reset the animation itself.
    Animation::resetObject();

    // Set the initial alpha value.
    object_.setAlpha(initialAlpha_);
}
