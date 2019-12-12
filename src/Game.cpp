#include "Directions.hpp"
#include "Unit.hpp"
#include "Game.hpp"
#include "debug.hpp"

void Game::draw_background() {
    for(auto e: rooms){
        for (const auto& v: e->map) {
            for (auto* object: v) {
                window->draw(object->background);

                /*if (object->solid_height != 0) {
                    window->draw(object->solid_part);
                }*/

            }
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

/*void Game::complete_drawing() {
    // Draws the upper parts of solid blocks
    for(auto e:rooms){
        for (const auto& v: e->map) {
            for (auto* object: v) {
                if (object->solid_height != 0) {
                    window->draw(object->upper_part);
                }
            }
        }
    }
}
*/
void Game::loop() {
    view.setCenter(player->get_position_x(), player->get_position_y());
    window->setView(view);
    while (window->isOpen()) {
        sf::sleep(sf::milliseconds(0));
        window->clear();
        draw_background();
        tick();
        player->move();
        window->draw(player->get_sprite());
        // complete_drawing();
        view.setCenter(player->get_position_x(), player->get_position_y());
        window->setView(view);
        window->display();
    }
}