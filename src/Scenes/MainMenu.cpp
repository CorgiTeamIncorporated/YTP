#include "../Config.hpp"
#include "MainMenu.hpp"

YDC::MainMenu::MainMenu(Content& content) :
    Scene(content),
    background_(content, "MenuBackground"),
    backgroundFadeIn_(background_, sf::seconds(0.3)),
    backgroundFadeOut_(background_, sf::seconds(0.3), 255, 0),
    block_(content, sf::Vector2f(50, 50)),
    blockFadeIn_(block_, sf::seconds(0.3)),
    blockFadeOut_(block_, sf::seconds(0.3), 255, 0),
    startButtonText_("Start the Game", content.getFont("Alata")),
    startButton_(content, startButtonText_),
    quitButtonText_("Quit the Game", content.getFont("Alata")),
    quitButton_(content, quitButtonText_)
{
    // Set the start button position.
    startButton_.setLocalPosition(sf::Vector2f(0, -50));

    // Add the start button to the block.
    block_.addObject(&startButton_);

    // Set the quit button position.
    quitButton_.setLocalPosition(sf::Vector2f(0, 50));

    // Add the quit button to the block.
    block_.addObject(&quitButton_);

    // Set the first act of the scene.
    setCurrentAct(static_cast<Act>(&fadeInBackground));
}

YDC::MainMenu::~MainMenu()
{
}

void YDC::MainMenu::fadeInBackground(sf::RenderWindow& window)
{
    if (backgroundFadeIn_.getDone())
    {
        // Reset the background fade in animation.
        backgroundFadeIn_.resetObject();

        // Set the button block fade in act.
        setCurrentAct(static_cast<Act>(&fadeInButtons));

        // Execute the next act.
        fadeInButtons(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the fading in background.
    backgroundFadeIn_.drawObject(window);
}

void YDC::MainMenu::fadeInButtons(sf::RenderWindow& window)
{
    // Draw the background.
    background_.draw(window);

    if (blockFadeIn_.getDone())
    {
        // Reset the button block fade in animation.
        blockFadeIn_.resetObject();

        // Set the stand by and wait act.
        setCurrentAct(static_cast<Act>(&standBy));

        // Execute the next act.
        standBy(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the fading in button block.
    blockFadeIn_.drawObject(window);
}

void YDC::MainMenu::fadeOut(sf::RenderWindow& window)
{
    if (backgroundFadeOut_.getDone() && blockFadeOut_.getDone())
    {
        // Reset the background fade out animation.
        backgroundFadeOut_.resetObject();

        // Reset the button block fade out animation.
        blockFadeOut_.resetObject();

        // Set the tile field scene.
        content_.setCurrentScene("TileField");

        // Return and move on to the next scene.
        return;
    }

    // Draw the fading out background.
    backgroundFadeOut_.drawObject(window);

    // Draw the fading out button block.
    blockFadeOut_.drawObject(window);
}

void YDC::MainMenu::standBy(sf::RenderWindow& window)
{
    if (quitButton_.getClicked())
    {
        // Close the window.
        window.close();

        // Return as nothing is left to do.
        return;
    }

    if (startButton_.getClicked())
    {
        // Set the fade out act.
        setCurrentAct(static_cast<Act>(&fadeOut));

        // Execute the next act.
        fadeOut(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the background.
    background_.draw(window);

    // DRaw the button block.
    block_.draw(window);
}
