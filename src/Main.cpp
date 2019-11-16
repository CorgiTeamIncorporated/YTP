#include <cstdlib>
#include <exception>
#include "Game.hpp"
#include "Main.hpp"

int main(int argc, char** argv)
{
    YDC::Game game;
    try
    {
        game.handleInitialization();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& exception)
    {
        game.handleException(exception);
        return EXIT_FAILURE;
    }
}
