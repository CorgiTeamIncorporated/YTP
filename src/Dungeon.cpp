#include "Scenes/Dungeon.hpp"
#include <iostream>

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

    // Drawing health bar
    window.draw(*health_outline);
    window.draw(*health_bar);

    // Saving changes on the screen
    window.display();
}

void Dungeon::adjust_sizes(sf::RenderWindow& window, sf::Event event) {
    float real_height = current_room->height * tile_size;
    float real_width = current_room->width * tile_size;

    float width = event.size.width,
          height = event.size.height;

    float scale = height / real_height;

    if (width < scale * real_width) {
        width = scale * real_width;
        window.setSize(sf::Vector2u(width, height));
    }

    float offset = (width - scale * real_width) / 2.0;

    sf::View view(sf::FloatRect(0, 0, real_width, real_height));

    view.setViewport(sf::FloatRect(offset / width, 0.f,
                                   scale * real_width / width, 1.f));

    window.setView(view);
}

void Dungeon::update(sf::RenderWindow& window) {
    sf::Time delta = timer.restart(); sf::Event event;

    while (window.pollEvent(event))
        if (event.type == sf::Event::Resized)
            adjust_sizes(window, event);
        else if (event.type == sf::Event::Closed)
            window.close();
        else
            handle_event(event);

    player->move(delta);

    for (AbstractEnemy* enemy: current_room->enemies)
        enemy->ai_move(delta);

    unsigned short health_bar_height = health_bar->getTextureRect().height;
    unsigned short step = 3;

    health_bar->setTextureRect(
        sf::IntRect(0, 0, step * player->health, health_bar_height)
    );
}

void Dungeon::handle_event(sf::Event event) {
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

void Dungeon::preload(sf::RenderWindow& window) {
    health_bar_texture.loadFromFile("textures/health.png");
    health_outline_texture.loadFromFile("textures/health-outline.png");

    health_bar = new sf::Sprite(health_bar_texture);
    health_outline = new sf::Sprite(health_outline_texture);

    health_outline->setPosition(
        window.getSize().x - health_outline->getTextureRect().width, 0
    );

    health_bar->setPosition(
        health_outline->getPosition() + sf::Vector2f(36, 8)
    );
}

void Dungeon::set_tile_size(unsigned int size) {
    this->tile_size = size;
}