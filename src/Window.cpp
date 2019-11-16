#include "Config.hpp"
#include "Window.hpp"

YDC::Window::Window(Content& content) :
    content_(content),
    window_(createVideoMode(), Config::APP_NAME)
{
}

YDC::Window::~Window()
{
}

void YDC::Window::createEventLoop()
{
    while (window_.pollEvent(event_))
    {
        events_.handle(event_, window_);
    }
}

void YDC::Window::createMainLoop()
{
    while (window_.isOpen())
    {
        createEventLoop();
        drawCurrentScene();
    }
}

const sf::VideoMode YDC::Window::createVideoMode() const
{
    #if defined(SFML_SYSTEM_ANDROID) || defined(SFML_SYSTEM_IOS)
        return sf::VideoMode(sf::VideoMode::getDesktopMode());
    #else
        return sf::VideoMode(Config::WIN_WIDTH, Config::WIN_HEIGHT);
    #endif
}

void YDC::Window::drawCurrentScene()
{
    window_.clear();
    content_.getCurrentScene().run(window_);
    window_.display();
}
