#include "Scenes/Dungeon.hpp"

void Dungeon::render(sf::RenderWindow& window) {
    // Drawing background
    for (const auto& v: current_room->map) {
        for (auto* object: v) {
            window.draw(object->background);

            if (object->solid_height != 0) {
                window.draw(object->solid_part);
            }
        }
    }

    // Drawing the player
    window.draw(player->get_sprite());

    // Drawing the enemies
    for (AbstractEnemy* enemy: current_room->enemies)
        window.draw(enemy->get_sprite());

    // Drawing upperground
    for (const auto& v: current_room->map) {
        for (auto* object: v) {
            if (object->solid_height != 0) {
                window.draw(object->upper_part);
            }
        }
    }
}

void Dungeon::update(sf::RenderWindow& window) {
    sf::Time delta = timer.restart();

    player->move(delta);

    for (AbstractEnemy* enemy: current_room->enemies)
        enemy->ai_move(delta);
}

void Dungeon::handle_event(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
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

void Dungeon::set_player(Unit* player) {
    this->player = player;
    this->player->dungeon_ptr = this;
}

void Dungeon::set_room(GameRoom* room) {
    this->current_room = room;
}

void Dungeon::preload() {
    return;
}

void Dungeon::set_tile_size(unsigned int size) {
    this->tile_size = size;
}
