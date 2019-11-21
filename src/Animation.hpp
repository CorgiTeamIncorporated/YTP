#ifndef YDC_ANIMATION_HPP_
#define YDC_ANIMATION_HPP_

#include <SFML/Graphics.hpp>
#include "Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// An animation base.
    ///
    /// @note Do not forget to call base's getDone,
    /// drawObject and resetObject in a derived class.
    /// They reset the timer so animation is considered
    /// started with the first draw call.
    class Animation
    {
    public:
        /// Constructs a new animation instance.
        ///
        /// @param object The object to bind the animation to.
        Animation(Object& object);

        /// Constructs a new animation instance.
        ///
        /// @param object The object to bind the animation to.
        /// @param time The time required to finish the animation.
        Animation(Object& object, const sf::Time& time);

        /// Destructs the animation instance.
        ~Animation();

        /// Gets whether the animation is done.
        ///
        /// @return Whether the animation is done.
        virtual bool getDone() const;

        /// Draws the sprite/shape animated.
        ///
        /// @param window The window handler.
        virtual void drawObject(sf::RenderWindow& window);

        /// Resets the style of the animated object.
        //// Also allows to run the animation again.
        virtual void resetObject();

    protected:
        /// The initial alpha value of the object.
        sf::Uint8 initialAlpha_;

        /// The initial position of the object.
        sf::Vector2f initialPosition_;

        /// The object the animation is binded to.
        Object& object_;

        /// Whether the animation started its execution.
        bool started_ = false;

        /// The time require to finish the animation.
        sf::Time time_ = sf::seconds(1);

        /// The timer.
        sf::Clock timer_;
    };
}

#endif // YDC_ANIMATION_HPP_
