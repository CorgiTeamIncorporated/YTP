#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"

void Game::draw_background() {
    for (const auto& v: current_room->map) {
        for (auto* object: v) {
            window->draw(object->sprite);
        }
    }
}

void Game::tick() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W)
                player->direction = Directions::Up;
            else if (event.key.code == sf::Keyboard::A)
                player->direction = Directions::Left;
            else if (event.key.code == sf::Keyboard::S)
                player->direction = Directions::Down;
            else if (event.key.code == sf::Keyboard::D)
                player->direction = Directions::Right;
        } else if (event.type == sf::Event::KeyReleased) {
            sf::Vector2f expected;

            if (event.key.code == sf::Keyboard::W)
                expected = Directions::Up;
            else if (event.key.code == sf::Keyboard::A)
                expected = Directions::Left;
            else if (event.key.code == sf::Keyboard::S)
                expected = Directions::Down;
            else if (event.key.code == sf::Keyboard::D)
                expected = Directions::Right;

            if (player->direction == expected)
                player->direction = Directions::NullDirection;
        }
    }
}

void Game::loop() {
    while (window->isOpen()) {
        window->clear();
        draw_background();
        tick();
        player->move();
        window->draw(player->get_sprite());
        window->display();
    }
}