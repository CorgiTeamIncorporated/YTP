#ifndef YDC_OBJECTS_TILES_HPP_
#define YDC_OBJECTS_TILES_HPP_

#include <deque>
#include <utility>
#include <SFML/Graphics.hpp>
#include "../Config.hpp"
#include "../Content.hpp"
#include "../Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// Tiles that constructs the game field.
    class Tiles : public Object
    {
    public:
        /// Constructs a new tiles instance.
        ///
        /// @param content The game content.
        /// @param types The deque of the types of the tiles.
        Tiles(Content& content, std::deque< std::deque<sf::Uint8> >& types);

        /// Destructs the tiles instance.
        ~Tiles();

        /// Draws the tiles.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Draws the solid tiles.
        ///
        /// @param window The window handler.
        void drawSolid(sf::RenderWindow& window);

        /// Sets the alpha color value of the tiles.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

    private:
        /// The tiles alpha sprite.
        sf::Sprite alpha_;

        /// The tiles sprite.
        sf::Sprite sprite_;

        /// The types deque.
        const std::deque< std::deque<sf::Uint8> > types_;

        /// The tiles types mapping.
        std::pair<sf::IntRect, sf::IntRect> typesMapping_[10] =
        {
            // The default tile (#0).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 0)),

            // The top border corner (#1).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 5, TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The bottom border corner (#2).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 5, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The left border corner (#3).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 4, TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The right border corner (#4).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 4, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The top-left border corner (#5).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 6, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The top-right border corner (#6).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 7, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The bottom-left border corner (#7).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 6, TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The bottom-right border corner (#8).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 7, TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE * 1)),

            // The rock tile (#9).
            std::pair<sf::IntRect, sf::IntRect>(sf::IntRect(TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE * 1), sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 0, TILE_SIZE * 1, TILE_SIZE * 1)),
        };

        /// Adds the borders to the types deque.
        ///
        /// @param types The initial types deque.
        ///
        /// @return The type array with the borders.
        std::deque< std::deque<sf::Uint8> >& addBorders(std::deque< std::deque<sf::Uint8> >& types) const;

        /// Draws the tile.
        ///
        /// @param window The window handler.
        /// @param height The height to draw the tile on.
        /// @param width The width to draw the tile on.
        void drawTile(sf::RenderWindow& window, size_t height, size_t width);

        /// Draws the solid tile.
        ///
        /// @param window The window handler.
        /// @param height The height to draw the tile on.
        /// @param width The width to draw the tile on.
        void drawTileSolid(sf::RenderWindow& window, size_t height, size_t width);
    };
}

#endif // YDC_OBJECTS_TILES_HPP_
