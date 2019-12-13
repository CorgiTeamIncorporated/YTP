#include "Scenes/Dungeon.hpp"
#include "GameSprites.hpp"
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

    // Drawing the enemies
    for (AbstractEnemy* enemy: current_room->enemies) {
        if (!enemy->killed()) {
            window.draw(enemy->get_sprite());
        }
    }

    // Drawing the player
    window.draw(player->get_sprite());

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

    timer.restart();
}

void Dungeon::update(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event))
        if (event.type == sf::Event::Resized)
            adjust_sizes(window, event);
        else if (event.type == sf::Event::Closed)
            window.close();
        else
            handle_event(event);

    sf::Time delta = timer.restart(); 

    player->move(delta);

    check_rooms();

    unsigned short vector_len = current_room->enemies.size();

    for (int i = 0; i < vector_len; i++) {
        AbstractEnemy* enemy = current_room->enemies[i];

        if (!enemy->killed()) {
            enemy->ai_move(delta);
        }
    }

    if (player->health < 0) {
        // Here are some actions when player died
        player->health = 0;
    }

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

        if (player->direction == expected) {
            player->direction = Directions::NullDirection;
            player->sprite->set_frame(0);
        }
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
    health_bar = &GameSprites::HealthBar;
    health_outline = &GameSprites::HealthOutline;

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

void Dungeon::check_rooms() {
    // This function checks if player intersects any door
    // In that case, function will replace
    // the room pointer with another one

    // Getting boundaries of each door
    float hor_middle = (current_room->width / 2) * tile_size;
    float ver_middle = (current_room->height / 2) * tile_size;
    float right_side = (current_room->width - 1) * tile_size;
    float bottom_side = (current_room->height - 1) * tile_size;

    sf::FloatRect up(hor_middle, 0, tile_size, tile_size);
    sf::FloatRect left(0, ver_middle, tile_size, tile_size);
    sf::FloatRect right(right_side, ver_middle, tile_size, tile_size);
    sf::FloatRect bottom(hor_middle, bottom_side, tile_size, tile_size);

    // Check if player intersects any door
    sf::FloatRect solid_bounds = player->get_solid_bounds();
    sf::FloatRect player_bounds = player->get_bounds();

    if (current_room->up != nullptr && up.intersects(solid_bounds)) {
        current_room = current_room->up;
        player->set_position(sf::Vector2f(player_bounds.left, bottom.top - tile_size));
    } else if (current_room->down != nullptr && bottom.intersects(solid_bounds)) {
        current_room = current_room->down;
        player->set_position(sf::Vector2f(player_bounds.left, up.top + tile_size));
    } else if (current_room->left != nullptr && left.intersects(solid_bounds)) {
        current_room = current_room->left;
        player->set_position(sf::Vector2f(right.left - tile_size, player_bounds.top));
    } else if (current_room->right != nullptr && right.intersects(solid_bounds)) {
        current_room = current_room->right;
        player->set_position(sf::Vector2f(left.left + tile_size, player_bounds.top));
    }
}

void Dungeon::attack_player(unsigned short damage) {
    player->health -= damage;
}