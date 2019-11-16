#include "Events.hpp"

YDC::Events::Events()
{
}

YDC::Events::~Events()
{
}

void YDC::Events::handle(sf::Event& event, sf::RenderWindow& window)
{
    handleClose(event, window);
    handleResize(event, window);
}

void YDC::Events::handleClose(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

void YDC::Events::handleResize(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type != sf::Event::Resized)
    {
        return;
    }
    if (event.size.width < Config::MIN_WIDTH && event.size.height < Config::MIN_HEIGHT)
    {
        window.setSize(sf::Vector2u(Config::MIN_WIDTH, Config::MIN_HEIGHT));
    }
    else if (event.size.height < Config::MIN_HEIGHT)
    {
        window.setSize(sf::Vector2u(window.getSize().x, Config::MIN_HEIGHT));
    }
    else if (event.size.width < Config::MIN_WIDTH)
    {
        window.setSize(sf::Vector2u(Config::MIN_WIDTH, window.getSize().y));
    }
    window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
}
