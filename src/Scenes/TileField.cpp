#include <deque>
#include "TileField.hpp"

YDC::TileField::TileField(Content& content) :
    Scene(content),
    player_(content, "Player"),
    playerMovement_(player_, sf::seconds(0.5)),
    tiles_(content, types_),
    tilesFadeIn_(tiles_, sf::seconds(0.3)),
    tilesFadeOut_(tiles_, sf::seconds(0.3), 255, 0)
{
    // Set the first act.
    setCurrentAct(static_cast<Act>(&fadeInField));
}

YDC::TileField::~TileField()
{
}

void YDC::TileField::fadeInField(sf::RenderWindow& window)
{
    if (tilesFadeIn_.getDone())
    {
        // Reset the tiles fade in animation.
        tilesFadeIn_.resetObject();

        // Set the stand by and wait act.
        setCurrentAct(static_cast<Act>(&standBy));

        // Execute the next act.
        standBy(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the fading in tiles.
    tilesFadeIn_.drawObject(window);

    // Draw the player.
    player_.draw(window);

    // Draw the fading in solid tiles.
    tiles_.drawSolid(window);
}

void YDC::TileField::movePlayer(sf::RenderWindow& window)
{
    if (playerMovement_.getDone())
    {
        // Reset the tiles fade in animation.
        playerMovement_.resetObject();

        // Set the stand by and wait act.
        setCurrentAct(static_cast<Act>(&standBy));

        // Execute the next act.
        standBy(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the fading in tiles.
    tiles_.draw(window);

    // Draw the player.
    playerMovement_.drawObject(window);

    // Draw the fading in solid tiles.
    tiles_.drawSolid(window);
}

void YDC::TileField::standBy(sf::RenderWindow& window)
{
    if (player_.expectMove())
    {
        // Set the state for the player.
        player_.setState(player_.fetchState());

        // Reset the player movement.
        player_.resetMovement();

        // Set the move player act.
        setCurrentAct(static_cast<Act>(&movePlayer));

        // Execute the next act.
        movePlayer(window);

        // Return and move on to the next act.
        return;
    }

    // Draw the tiles.
    tiles_.draw(window);

    // Handle the player movement.
    player_.handleMovement();

    // Draw the player.
    player_.draw(window);

    // Sraw the solid tiles.
    tiles_.drawSolid(window);
}
