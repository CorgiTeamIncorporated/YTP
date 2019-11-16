#ifndef YDC_WINDOW_HPP_
#define YDC_WINDOW_HPP_

#include <SFML/Graphics.hpp>
#include "Content.hpp"
#include "Events.hpp"

namespace YDC
{
    /// A window used to output stuff.
    class Window
    {
    public:
        /// Constructs a new window.
        ///
        /// @param content The game content.
        Window(Content& content);

        /// Destructs the window.
        ~Window();

        /// Creates a main loop.
        void createMainLoop();

    private:
        /// The game content reference.
        Content& content_;

        /// The polled SFML event pointer.
        sf::Event event_;

        /// The events.
        Events events_;

        /// The SFML render window instance.
        sf::RenderWindow window_;

        /// Creates an event loop.
        void createEventLoop();

        /// Creates a platform-specific video mode.
        ///
        /// @return The platform-sprcific video mode.
        const sf::VideoMode createVideoMode() const;

        /// Draws the current frame in the window.
        void drawCurrentScene();
    };
} // YDC

#endif // YDC_WINDOW_HPP_
