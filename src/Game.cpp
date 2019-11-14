#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"

void Game::tick() {
    window->clear();

    // Drawing background
    for (const auto& v: current_room->map) {
        for (auto* object: v) {
            window->draw(object->sprite);
        }
    }

    // Moving the player
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::W:
                    player->move(Directions::Up);
                    break;
                case sf::Keyboard::A:
                    player->move(Directions::Left);
                    break;
                case sf::Keyboard::S:
                    player->move(Directions::Down);
                    break;
                case sf::Keyboard::D:
                    player->move(Directions::Right);
                    break;
            }
        }
    }

    window->draw(player->get_sprite());
    window->display();
}

void Game::loop() {
    while (window->isOpen()) {
        tick();
    }
}