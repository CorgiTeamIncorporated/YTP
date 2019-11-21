#include <cstdlib>
#include <iostream>
#include "Scenes/LoadScreen.hpp"
#include "Config.hpp"
#include "Game.hpp"

// See: Game.hpp.
YDC::Game::Game() :
    window_(createVideoMode(), APP_NAME, sf::Style::Default)
{
}

// See: Game.hpp.
YDC::Game::~Game()
{
}

// See: Game.hpp.
void YDC::Game::createEventLoop()
{
    while (window_.pollEvent(event_))
    {
        // Handle the close event.
        handleClose(event_, window_);

        // Handle the resize event.
        handleResize(event_, window_);
    }
}

// See: Game.hpp.
void YDC::Game::createMainLoop()
{
    while (window_.isOpen())
    {
        // Create the event loop.
        createEventLoop();

        // Clear the current window state.
        window_.clear();

        // Run the current scene.
        content_.getCurrentScene().run(window_);

        // Draw the content in the window.
        window_.display();
    }
}

// See: Game.hpp.
const sf::VideoMode YDC::Game::createVideoMode() const
{
#if defined(SFML_SYSTEM_ANDROID) || defined(SFML_SYSTEM_IOS)
    // Return the desktop mode window.
    return sf::VideoMode(sf::VideoMode::getDesktopMode());
#else
    // Return the pre-set height and width window.
    return sf::VideoMode(WIN_WIDTH, WIN_HEIGHT);
#endif
}

// See: Game.hpp.
void YDC::Game::handleClose(const sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
    {
        // Close the window.
        window.close();
    }
}

// See: Game.hpp.
int YDC::Game::handleException(const std::exception& exception) const noexcept
{
    // Output the exception to STDOUT and leave it at that.
    std::cout << "Exception: " << exception.what() << std::endl;

    // Exit with a failure.
    return EXIT_FAILURE;
}

// See: Game.hpp.
void YDC::Game::handleResize(const sf::Event& event, sf::RenderWindow& window)
{
    if (event.type != sf::Event::Resized)
    {
        // Stop the wrong event from continuing.
        return;
    }

    if (event.size.width < MIN_WIDTH && event.size.height < MIN_HEIGHT)
    {
        // Reset both horizontal and vertical window size.
        window.setSize(sf::Vector2u(MIN_WIDTH, MIN_HEIGHT));
    }
    else if (event.size.height < MIN_HEIGHT)
    {
        // Reset only vertical window size.
        window.setSize(sf::Vector2u(window.getSize().x, MIN_HEIGHT));
    }
    else if (event.size.width < MIN_WIDTH)
    {
        // Reset only horizontal window size.
        window.setSize(sf::Vector2u(MIN_WIDTH, window.getSize().y));
    }

    // Update the window view.
    window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
}

// See: Game.hpp.
int YDC::Game::handleInitialization()
{
    // Load the first scene of the game.
    content_.addScene("LoadScreen", new LoadScreen(content_));

    // Set it as the current scene.
    content_.setCurrentScene("LoadScreen");

    // Create the main game loop.
    createMainLoop();

    // Exit with a success.
    return EXIT_SUCCESS;
}
