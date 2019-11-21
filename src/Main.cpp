#include <exception>
#include "Game.hpp"
#include "Main.hpp"

// See: Main.hpp.
int main(int argc, char** argv)
{
    // Create a new game instance.
    YDC::Game game;

    try
    {
        // Initialize the game.
        return game.handleInitialization();
    }
    catch (const std::exception& exception)
    {
        // Handle the exception.
        return game.handleException(exception);
    }
}
