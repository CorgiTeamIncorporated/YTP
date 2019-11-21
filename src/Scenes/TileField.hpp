#ifndef YDC_SCENES_TILEFIELD_HPP_
#define YDC_SCENES_TILEFIELD_HPP_

#include <SFML/Graphics.hpp>
#include "../Animations/Fade.hpp"
#include "../Animations/Movement.hpp"
#include "../Objects/Entities/Player.hpp"
#include "../Objects/Tiles.hpp"
#include "../Content.hpp"
#include "../Scene.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A tile field - primary walking area.
    class TileField : public Scene
    {
    public:
        /// Constructs a new tile field instance.
        ///
        /// @param content The game content.
        TileField(Content& content);

        /// Destructs the tile field instance.
        ~TileField();

        /// Fades in the tile field.
        ///
        /// @param window The window handler.
        void fadeInField(sf::RenderWindow& window);

        /// Moves the player in the tile field.
        ///
        /// @param window The window handler.
        void movePlayer(sf::RenderWindow& window);

        /// Stands by on the tile field.
        ///
        /// @param window The window handler.
        void standBy(sf::RenderWindow& window);

    private:
        /// The player.
        Player player_;

        /// The player movement.
        Movement playerMovement_;

        /// The tiles types.
        std::deque< std::deque<sf::Uint8> > types_
        {
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 0, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
            std::deque<sf::Uint8>{0, 0, 9, 0, 9, 9, 9, 0, 0, 0, 9, 0, 9, 9, 9, 0},
        };

        /// The tiles.
        Tiles tiles_;

        /// The tiles fade-in.
        Fade tilesFadeIn_;

        /// The tiles fade-out.
        Fade tilesFadeOut_;
    };
}

#endif // YDC_SCENES_TILEFIELD_HPP_
