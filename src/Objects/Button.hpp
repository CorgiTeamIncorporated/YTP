#ifndef YDC_OBJECTS_BUTTON_HPP_
#define YDC_OBJECTS_BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include "../Content.hpp"
#include "../Object.hpp"

// See: Config.hpp.
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

        /// Constructs a new button instance.
        ///
        /// @param content The game content.
        /// @param text The text of the button.
        Button(Content& content, sf::Text& text);

        /// Destructs the button instance.
        ~Button();

        /// Draws the button.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Gets whether the button is clicked.
        ///
        /// @return Whether a button is clicked.
        bool getClicked();

        /// Sets the alpha color value of the button.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

    private:
        /// Whether the button is clicked.
        bool clicked_ = false;

        /// Whether the button is hovered.
        bool hovered_ = false;

        /// The sprite copy.
        sf::Sprite sprite_;

        /// The button size.
        sf::Vector2f size_;

        /// The button text.
        sf::Text text_;

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

        /// Sets the sprite position. Doesn't affect the text position.
        void setSpritePosition();

        /// Sets the proper sprite rectangle, according to the state.
        ///
        /// @param window The window handler.
        void setSpriteRectangle(sf::RenderWindow& window);

        /// Sets the text position and centers it according to the button size.
        void setTextPosition();
    };
}

#endif // YDC_OBJECTS_BUTTON_HPP_
