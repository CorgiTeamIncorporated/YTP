#ifndef YDC_GAME_HPP_
#define YDC_GAME_HPP_

#include <exception>
#include <SFML/Graphics.hpp>
#include "Content.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A common game start point.
    class Game
    {
    public:
        /// Constructs a new game instance.
        Game();

        /// Destructs the game instance.
        ~Game();

        /// Handles any exceptions risen during `handleInitialization`.
        ///
        /// @param exception The exception to handle.
        int handleException(const std::exception& exception) const noexcept;

        /// Handles the game initialization.
        int handleInitialization();

    private:
        /// The game content.
        Content content_;

        /// The polled SFML event pointer.
        sf::Event event_;

        /// The SFML render window instance.
        sf::RenderWindow window_;

        /// Creates an event loop.
        void createEventLoop();

        /// Creates a main loop.
        void createMainLoop();

        /// Creates a platform-specific video mode.
        ///
        /// @return The platform-sprcific video mode.
        const sf::VideoMode createVideoMode() const;

        /// Handle the close events.
        ///
        /// @param event The polled SFML event.
        /// @param window The window handler.
        void handleClose(const sf::Event& event, sf::RenderWindow& window);

        /// Handle the resize events.
        ///
        /// @param event The polled SFML event.
        /// @param window The window handler.
        void handleResize(const sf::Event& event, sf::RenderWindow& window);
    };
}

#endif // YDC_GAME_HPP_
