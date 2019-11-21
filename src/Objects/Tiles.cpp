#include "Tiles.hpp"

// See: Objects/Tiles.hpp.
YDC::Tiles::Tiles(Content& content, std::deque< std::deque<sf::Uint8> >& types) :
    Object(content),
    alpha_(content.getSpriteCopy("TilesAlpha")),
    sprite_(content.getSpriteCopy("Tiles")),
    types_(addBorders(types))
{
}

// See: Objects/Tiles.hpp.
YDC::Tiles::~Tiles()
{
    // Delete the alpha sprite.
    delete &alpha_;

    // Delete the sprite.
    delete &sprite_;
}

// See: Objects/Tiles.hpp.
std::deque< std::deque<sf::Uint8> >& YDC::Tiles::addBorders(std::deque< std::deque<sf::Uint8> >& types) const
{
    // Create the first border row.
    std::deque<sf::Uint8> first(FIELD_WIDTH, 1);

    // Create the last border row.
    std::deque<sf::Uint8> last(FIELD_WIDTH, 2);

    // Set the top-left corner.
    first.push_front(5);

    // Set the top-right corener.
    first.push_back(6);

    // Set the botton-left corener.
    last.push_front(7);

    // Set the bottom-right corner.
    last.push_back(8);

    for (auto& type : types)
    {
        // Push the left border.
        type.push_front(3);

        // Push the right border.
        type.push_back(4);
    }

    // Push the first row.
    types.push_front(first);

    // Push the last row.
    types.push_back(last);

    // Return the updated deque.
    return types;
}

// See: Objects/Tiles.hpp.
void YDC::Tiles::draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < FIELD_HEIGHT + 2; ++i)
    {
        for (size_t j = 0; j < FIELD_WIDTH + 2; ++j)
        {
            // Draw the tile.
            drawTile(window, i, j);
        }
    }
}

// See: Objects/Tiles.hpp.
void YDC::Tiles::drawTile(sf::RenderWindow& window, size_t height, size_t width)
{
    // Set the sprite position.
    sprite_.setPosition(sf::Vector2f(TILE_SIZE * width, TILE_SIZE * height));

    // Set the sprite rectangle.
    sprite_.setTextureRect(typesMapping_[types_[height][width]].first);

    // Draw the sprite.
    window.draw(sprite_);
}

// See: Objects/Tiles.hpp.
void YDC::Tiles::drawSolid(sf::RenderWindow& window)
{
    for (size_t i = 0; i < FIELD_HEIGHT + 2; ++i)
    {
        for (size_t j = 0; j < FIELD_WIDTH + 2; ++j)
        {
            // Draw the solid tile.
            drawTileSolid(window, i, j);
        }
    }
}

// See: Objects/Tiles.hpp.
void YDC::Tiles::drawTileSolid(sf::RenderWindow& window, size_t height, size_t width)
{
    // Set the sprite position.
    sprite_.setPosition(sf::Vector2f(TILE_SIZE * width, TILE_SIZE * height));

    // Set the sprite rectangle.
    sprite_.setTextureRect(typesMapping_[types_[height][width]].second);

    // Draw the sprite.
    window.draw(sprite_);
}

// See: Objects/Tiles.hpp.
void YDC::Tiles::setAlpha(const sf::Uint8& alpha)
{
    // Set the sprite color with the alpha value.
    sprite_.setColor(sf::Color(sprite_.getColor().r, sprite_.getColor().g, sprite_.getColor().b, alpha));
}
