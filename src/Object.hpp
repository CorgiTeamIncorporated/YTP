#ifndef YDC_OBJECT_HPP_
#define YDC_OBJECT_HPP_

#include <SFML/Graphics.hpp>
#include "Content.hpp"

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

        /// Destructs the object.
        ~Object();

        /// Draws the object.
        ///
        /// @param window The window to render the object in.
        virtual void draw(sf::RenderWindow& window) = 0;

        /// Sets the alpha color value of the object, if possible.
        ///
        /// @param alpha The alpha color value.
        virtual void setAlpha(const sf::Uint8& alpha);

    protected:
        /// The game content reference.
        Content& content_;
    };
} // YDC

#endif // YDC_OBJECT_HPP_
