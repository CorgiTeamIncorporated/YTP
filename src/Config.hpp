#ifndef YDC_CONFIG_HPP_
#define YDC_CONFIG_HPP_

#include <SFML/System.hpp>

/// The game namespace (YDC = Young Dungeon Creatures).
namespace YDC
{
    /// Game basic configuration.
    class Config
    {
    public:
        /// The default, non-translated application name.
        static const sf::String APP_NAME;

        /// The directory with the assets.
        static const sf::String ASSETS_DIR;

        /// The directory with the fonts.
        static const sf::String FONTS_DIR;

        /// The directory with the images.
        static const sf::String IMAGES_DIR;

        /// The minimal window height.
        static const sf::Uint16 MIN_HEIGHT;

        /// The minimal window width.
        static const sf::Uint16 MIN_WIDTH;

        /// The initial window height.
        static const sf::Uint16 WIN_HEIGHT;

        /// The initial window width.
        static const sf::Uint16 WIN_WIDTH;
    };
} // YDC

#endif // YDC_CONFIG_HPP_
