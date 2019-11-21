#ifndef YDC_OBJECTS_BLOCK_HPP_
#define YDC_OBJECTS_BLOCK_HPP_

#include <list>
#include <SFML/Graphics.hpp>
#include "../Content.hpp"
#include "../Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A block of some objects, for relative positioning.
    class Block : public Object
    {
    public:
        /// Constructs a new block instance.
        ///
        /// @param content The game content.
        /// @param relativePosition The relative position of the block.
        Block(Content& content, const sf::Vector2f& relativePosition);

        /// Destructs the block instance.
        ~Block();

        /// Adds an object to put in the block.
        void addObject(Object* instance);

        /// Draws the block.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Sets the alpha color value of the block.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

    private:
        /// The list of objects pointers this block is containing.
        std::list<Object*> objects_;

        /// The relative position in percents.
        sf::Vector2f relativePosition_;

        /// Calculates an absolute position based on our relative one.
        ///
        /// @return The current absolute position.
        const sf::Vector2f calculateAbsolutePosition(sf::RenderWindow& window);
    };
}

#endif // YDC_OBJECTS_BLOCK_HPP_
