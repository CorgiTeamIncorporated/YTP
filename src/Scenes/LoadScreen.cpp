#include "../Config.hpp"
#include "LoadScreen.hpp"
#include "MainMenu.hpp"

YDC::LoadScreen::LoadScreen(Content& content) :
    Scene(content),
    thread_(&LoadScreen::loadGame, this)
{
}

YDC::LoadScreen::~LoadScreen()
{
}

void YDC::LoadScreen::loadGame()
{
    content_.addFont("Tomorrow", Config::FONTS_DIR + "/Tomorrow.ttf");
    content_.addTexture("Button", Config::IMAGES_DIR + "/Button.png");
    content_.addTexture("MenuBackground", Config::IMAGES_DIR + "/MenuBackground.png");
    content_.getTexture("MenuBackground").setRepeated(true);
    content_.addSprite("Button", "Button");
    content_.addSprite("MenuBackground", "MenuBackground");
    content_.addScene("MainMenu", new MainMenu(content_));
    loaded_ = true;
}

void YDC::LoadScreen::run(sf::RenderWindow& window)
{
    if (loaded_)
    {
        thread_.join();
        content_.setCurrentScene("MainMenu");
    }
}
