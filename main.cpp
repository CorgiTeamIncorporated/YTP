#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include "GameManager.hpp"
#include "Enemies/Zombie.hpp"
#include "Enemies/Spikes.hpp"
#include "Enemies/FireBall.hpp"
#include "Enemies/FireMan.hpp"
#include <vector>
#include <iostream>
#include "Scenes/RegistrationSuggest.hpp"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(
        sf::VideoMode(500, 400), "YDC (C) Corgi Industries, 2k19",
        sf::Style::Default ^ sf::Style::Resize
    );

    window->setFramerateLimit(60);

    RegistrationSuggest* menu = new RegistrationSuggest;

    GameManager* manager = new GameManager(menu, window);
    manager->start();
}