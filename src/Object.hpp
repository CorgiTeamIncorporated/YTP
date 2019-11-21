#ifndef YDC_OBJECT_HPP_
#define YDC_OBJECT_HPP_

#include <SFML/Graphics.hpp>
#include "Content.hpp"

// See: Config.hpp.
namespace YDC
{
    /// An object (player, button, etc.).
    ///
    /// @note Use copies of contents when adding them to object.
    /// Using, for example, one sprite for several instances and
    /// then running animations on them simanteniously might lead
    /// to problems.
    class Object
    {
    public:
        /// Constructs a new object.
        ///
        /// @param content The game context.
        Object(Content& content);

        /// Constructs a new object.
        ///
        /// @param content The game context.
        /// @param position The position of the object.
        Object(Content& content, const sf::Vector2f& position);

        /// Destructs the object.
        ~Object();

        /// Draws the object.
        ///
        /// @param window The window to render the object in.
        virtual void draw(sf::RenderWindow& window) = 0;

        /// Gets the initial alpha value.
        ///
        /// @return The initial alpha value.
        virtual sf::Uint8 getInitialAlpha() const;

        /// Gets the initial position value.
        ///
        /// @return The initial position value.
        virtual sf::Vector2f getInitialPosition() const;

        /// Gets the local position value.
        ///
        /// @return The local position value.
        sf::Vector2f getLocalPosition() const;

        /// Gets the position value.
        ///
        /// @return The position value.
        sf::Vector2f getPosition() const;

        /// Sets the alpha color value of the object, if possible.
        ///
        /// @param alpha The alpha color value.
        virtual void setAlpha(const sf::Uint8& alpha);

        /// Sets the position of the object, if possible.
        ///
        /// @param position The new position.
        virtual void setPosition(const sf::Vector2f& position);

        /// Sets the local position of the object, if possible.
        ///
        /// @param position The new position.
        virtual void setLocalPosition(const sf::Vector2f& localPosition);

    protected:
        /// The game content reference.
        Content& content_;

        /// The object's window position (can be ignored for some objects).
        ///
        /// @note This position is relative to the window.
        sf::Vector2f position_ = sf::Vector2f(0, 0);

        /// The object's local position (can be ignored for some objects).
        ///
        /// @note The local position is relative to the global position, called just position.
        sf::Vector2f localPosition_ = sf::Vector2f(0, 0);
    };
}

#endif // YDC_OBJECT_HPP_
