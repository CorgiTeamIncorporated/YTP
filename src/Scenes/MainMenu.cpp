#include "../Config.hpp"
#include "MainMenu.hpp"

YDC::MainMenu::MainMenu(Content& content) :
    Scene(content),
    background_(content, "MenuBackground"),
    backgroundFade_(background_),
    quitButtonText_("Quit the Game", content.getFont("Tomorrow")),
    quitButton_(content, "Button", quitButtonText_)
{
}

YDC::MainMenu::~MainMenu()
{
}

void YDC::MainMenu::fadeInBackground(sf::RenderWindow& window)
{
    if (state_ != "Initial")
    {
        return;
    }
    if (backgroundFade_.getIsDone())
    {
        backgroundFade_.resetObject();
        state_ = "fadeInButtons";
        return;
    }
    backgroundFade_.drawObject(window);
}

void YDC::MainMenu::fadeInButtons(sf::RenderWindow& window)
{
    if (state_ != "fadeInButtons")
    {
        return;
    }
    background_.draw(window);
    quitButton_.draw(window);
}

void YDC::MainMenu::run(sf::RenderWindow& window)
{
    fadeInBackground(window);
    fadeInButtons(window);
}
