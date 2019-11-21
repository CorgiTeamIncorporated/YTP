#ifndef YDC_OBJECTS_BACKGROUND_HPP_
#define YDC_OBJECTS_BACKGROUND_HPP_

#include <SFML/Graphics.hpp>
#include "../Content.hpp"
#include "../Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A background for something.
    class Background : public Object
    {
    public:
        /// Constructs a new background instance.
        ///
        /// @param content The game content.
        /// @param spriteName The name of the sprite for the background.
        Background(Content& content, const sf::String& spriteName);

        /// Destructs the background instance.
        ~Background();

        /// Draws the background.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Sets the alpha color value of the background.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

    private:
        /// The sprite copy.
        sf::Sprite sprite_;
    };
}

#endif // YDC_OBJECTS_BACKGROUND_HPP_
