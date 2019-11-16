#ifndef YDC_EVENTS_HPP_
#define YDC_EVENTS_HPP_

#include <SFML/Graphics.hpp>
#include "Config.hpp"

namespace YDC
{
    /// Events used in the game.
    class Events
    {
    public:
        /// Constructs a new events instance.
        Events();

        /// Destructs the events instance.
        ~Events();

        /// Handle the events.
        ///
        /// @param event The polled SFML event.
        /// @param window The window handler.
        void handle(sf::Event& event, sf::RenderWindow& window);

        /// Handle the close events.
        ///
        /// @param event The polled SFML event.
        /// @param window The window handler.
        void handleClose(sf::Event& event, sf::RenderWindow& window);

        /// Handle the resize events.
        ///
        /// @param event The polled SFML event.
        /// @param window The window handler.
        void handleResize(sf::Event& event, sf::RenderWindow& window);
    };
} // YGC

#endif // YDC_EVENTS_HPP_
