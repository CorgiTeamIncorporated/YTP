#include "Animation.hpp"

YDC::Animation::Animation(Object& object) :
    object_(object)
{
}

YDC::Animation::~Animation()
{
}

bool YDC::Animation::getIsDone() const
{
    return started_;
}

void YDC::Animation::drawObject(sf::RenderWindow& window)
{
    if (!started_)
    {
        started_ = true;
        timer_.restart();
    }
}

void YDC::Animation::resetObject()
{
    started_ = false;
}
