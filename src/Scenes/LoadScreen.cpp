#include "../Config.hpp"
#include "LoadScreen.hpp"
#include "MainMenu.hpp"
#include "TileField.hpp"

// See: Scenes/LoadScreen.hpp.
YDC::LoadScreen::LoadScreen(Content& content) :
    Scene(content),
    thread_(&LoadScreen::loadGame, this)
{
    // Set the first act of the scene.
    setCurrentAct(static_cast<Act>(&checkThread));
}

// See: Scenes/LoadScreen.hpp.
YDC::LoadScreen::~LoadScreen()
{
}

// See: Scenes/LoadScreen.hpp.
void YDC::LoadScreen::changeToMainMenu(sf::RenderWindow& window)
{
    content_.setCurrentScene("MainMenu");
}

// See: Scenes/LoadScreen.hpp.
void YDC::LoadScreen::checkThread(sf::RenderWindow& window)
{
    if (loaded_)
    {
        // Join the main andgame loading threads.
        thread_.join();

        // Set the act that changes us to the main menu.
        setCurrentAct(static_cast<Act>(&changeToMainMenu));
    }
}

// See: Scenes/LoadScreen.hpp.
void YDC::LoadScreen::loadGame()
{
    // Add the default font.
    content_.addFont("Alata", FONTS_DIR + "/Alata.ttf");

    // Add the button texture and sprite.
    content_.addTextureAndSprite("Button", IMAGES_DIR + "/Button.png");

    // Add the menu background texture and sprite.
    content_.addTextureAndSprite("MenuBackground", IMAGES_DIR + "/MenuBackground.png");

    // Add the player texture and sprite.
    content_.addTextureAndSprite("Player", IMAGES_DIR + "/Player.png");

    // Add the tiles texture and sprite.
    content_.addTextureAndSprite("Tiles", IMAGES_DIR + "/Tiles.png");

    // Add the tiles alpha texture and sprite.
    content_.addTextureAndSprite("TilesAlpha", IMAGES_DIR + "/TilesAlpha.png");

    // Set the menu background texture as repeated.
    content_.getTexture("MenuBackground").setRepeated(true);

    // Add the main menu scene.
    content_.addScene("MainMenu", new MainMenu(content_));

    // Add the tile field scene.
    content_.addScene("TileField", new TileField(content_));

    // Set the game as loaded.
    loaded_ = true;
}
