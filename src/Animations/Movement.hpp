#ifndef YDC_ANIMATIONS_MOVEMENT_HPP_
#define YDC_ANIMATIONS_MOVEMENT_HPP_

#include <SFML/Graphics.hpp>
#include "../Objects/Entity.hpp"
#include "../Animation.hpp"

// See: Config.hpp.
namespace YDC
{
    /// Movement animations.
    class Movement : public Animation
    {
    public:
        /// Constructs a new movement animation instance for an object.
        ///
        /// @param entity The entity to move around.
        Movement(Entity& entity);

        /// Constructs a new movement animation instance for an object.
        ///
        /// @param entity The entity to move around.
        /// @param time The time required to finish the animation.
        Movement(Entity& entity, const sf::Time& time);

        /// Destructs the movement animation instance.
        ~Movement();

        /// Draws the sprite/shape animated.
        ///
        /// @param window The window handler.
        void drawObject(sf::RenderWindow& window);

        /// Gets whether the animation is done.
        ///
        /// @return Whether the animation is done.
        bool getDone() const;

        /// Resets the style of the animated object.
        void resetObject();

    private:
        /// Object is entity now.
        Entity& entity_;

        /// Gets the current position of the object.
        ///
        /// @return The current position of the object.
        sf::Vector2f getCurrentPosition() const;

        /// Gets the current position delta of the object.
        ///
        /// @return The current position delta of the object.
        float getCurrentPositionDelta() const;

        /// Gets the current step to use.
        ///
        /// @return The step.
        sf::Uint8 getCurrentStep() const;
    };
}

#endif // YDC_ANIMATIONS_MOVEMENT_HPP_
