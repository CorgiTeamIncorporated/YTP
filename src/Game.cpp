#include <iostream>
#include "Scenes/LoadScreen.hpp"
#include "Game.hpp"

YDC::Game::Game() :
    window_(content_)
{
}

YDC::Game::~Game()
{
}

void YDC::Game::handleException(const std::exception& exception) const noexcept
{
    std::cout << "Exception: " << exception.what() << std::endl;
}

void YDC::Game::handleInitialization()
{
    content_.addScene("LoadScreen", new LoadScreen(content_));
    content_.setCurrentScene("LoadScreen");
    window_.createMainLoop();
}
