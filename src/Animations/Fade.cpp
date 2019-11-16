#include "Fade.hpp"

YDC::Fade::Fade(Object& object) :
    Animation(object)
{
}

YDC::Fade::Fade(Object& object, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha) :
    Animation(object),
    endAlpha_(endAlpha),
    startAlpha_(startAlpha)
{
}

YDC::Fade::Fade(Object& object, const sf::Time& time) :
    Animation(object),
    time_(time)
{
}

YDC::Fade::Fade(Object& object, const sf::Time& time, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha) :
    Animation(object),
    endAlpha_(endAlpha),
    startAlpha_(startAlpha),
    time_(time)
{
}

YDC::Fade::~Fade()
{
}

void YDC::Fade::drawObject(sf::RenderWindow& window)
{
    Animation::drawObject(window);
    sf::Uint8 alpha = getCurrentAlpha();
    object_.setAlpha(alpha);
    object_.draw(window);
}

sf::Uint8 YDC::Fade::getCurrentAlpha() const
{
    sf::Int16 alpha = getCurrentAlphaWithError();
    if (alpha > endAlpha_)
    {
        return endAlpha_;
    }
    else if (alpha < startAlpha_)
    {
        return startAlpha_;
    }
    return alpha;
}

sf::Int16 YDC::Fade::getCurrentAlphaWithError() const
{
    return startAlpha_ + (endAlpha_ - startAlpha_) * (timer_.getElapsedTime() / time_);
}

bool YDC::Fade::getIsDone() const
{
    return Animation::getIsDone() && timer_.getElapsedTime() >= time_;
}

void YDC::Fade::resetObject()
{
    Animation::resetObject();
    object_.setAlpha(255);
}
