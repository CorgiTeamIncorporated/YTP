#ifndef YDC_ANIMATION_HPP_
#define YDC_ANIMATION_HPP_

#include <SFML/Graphics.hpp>
#include "Object.hpp"

namespace YDC
{
    /// An animation base.
    ///
    /// @note Do not forget to call base's getIsDone, drawObject and resetObject in a derived class.
    /// They reset the timer so animation is considered started with the first draw call.
    class Animation
    {
    public:
        /// Constructs a new animation instance.
        ///
        /// @param object The object to bind the animation to.
        Animation(Object& object);

        /// Destructs the animation instance.
        ~Animation();

        /// Gets whether the animation is done.
        ///
        /// @return Whether the animation is done.
        virtual bool getIsDone() const;

        /// Draws the sprite/shape animated.
        ///
        /// @param window The window handler.
        virtual void drawObject(sf::RenderWindow& window);

        /// Resets the style of the animated object.
        //// Also allows to run the animation again.
        virtual void resetObject();

    protected:
        /// The object the animation is binded to.
        Object& object_;

        /// Whether the animation started its execution.
        bool started_ = false;

        /// The timer.
        sf::Clock timer_;
    };
} // YDC

#endif // YDC_ANIMATION_HPP_
