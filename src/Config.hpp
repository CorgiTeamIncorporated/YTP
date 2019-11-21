#ifndef YDC_CONFIG_HPP_
#define YDC_CONFIG_HPP_

#include <SFML/System.hpp>

/// The game namespace (YDC = Young Dungeon Creatures).
namespace YDC
{
    /// The default, non-translated application name.
    const sf::String APP_NAME = "Young Dungeon Creatures";

    /// The directory with the assets.
    const sf::String ASSETS_DIR = "assets";

    /// The directory with the fonts.
    const sf::String FONTS_DIR = ASSETS_DIR + "/Fonts";

    /// The directory with the images.
    const sf::String IMAGES_DIR = ASSETS_DIR + "/Images";

    /// The generic entity height.
    const sf::Uint16 ENTITY_HEIGHT = 64;

    /// The generic entity step.
    const sf::Uint16 ENTITY_STEP = 15;

    // The amount of animation steps.
    const sf::Uint8 ENTITY_STEPS = 4;

    /// The generic entity width.
    const sf::Uint16 ENTITY_WIDTH = 43;

    /// The tile field height.
    const sf::Uint16 FIELD_HEIGHT = 16;

    /// The tile field width.
    const sf::Uint16 FIELD_WIDTH = 16;

    /// The minimal window height.
    const sf::Uint16 MIN_HEIGHT = 250;

    /// The minimal window width.
    const sf::Uint16 MIN_WIDTH = 250;

    /// The tile size.
    const sf::Uint16 TILE_SIZE = 64;

    /// The initial window height.
    const sf::Uint16 WIN_HEIGHT = 600;

    /// The initial window width.
    const sf::Uint16 WIN_WIDTH = 800;
}

#endif // YDC_CONFIG_HPP_
