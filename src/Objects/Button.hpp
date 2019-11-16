#ifndef YDC_OBJECTS_BUTTON_HPP_
#define YDC_OBJECTS_BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include "../Content.hpp"
#include "../Object.hpp"

namespace YDC
{
    /// A button for something.
    class Button : public Object
    {
    public:
        /// Constructs a new button instance.
        ///
        /// @param content The game content.
        /// @param spriteName The name of the sprite for the button.
        /// @param text The text of the button.
        Button(Content& content, const sf::String& spriteName, sf::Text& text);

        /// Destructs the button instance.
        ~Button();

        /// Draws the button.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Sets the alpha color value of the button.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

    private:
        /// The button position.
        sf::Vector2u position_ = sf::Vector2u(0, 0);

        /// The button size.
        sf::Vector2u size_;

        /// The sprite copy.
        sf::Sprite sprite_;

        /// The button text.
        sf::Text text_;

        /// Centers the text according to the button parameters.
        void centerText();

        /// Checks whether the button is clicked.
        ///
        /// @param window The window handler.
        bool isClicked(sf::RenderWindow& window);

        /// Checks whether the button is hovered upon.
        ///
        /// @param window The window handler.
        bool isHovered(sf::RenderWindow& window);

        /// Checks whether the button is hovered upon on X axis.
        ///
        /// @param window The window handler.
        bool isHoveredX(sf::RenderWindow& window);

        /// Checks whether the button is hovered upon on Y axis.
        ///
        /// @param window The window handler.
        bool isHoveredY(sf::RenderWindow& window);
    };
} // YDC

#endif // YDC_OBJECTS_BUTTON_HPP_
