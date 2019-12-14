#include "Scenes/Dungeon.hpp"
#include "SFML/Network.hpp"
#include "GameSprites.hpp"
#include <iostream>
#include <string>

void Dungeon::render(sf::RenderWindow& window) {
    if (player->killed()) {
        window.clear();
        window.draw(GameSprites::SplashScreen);
        window.display(); return;
    }

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

    // Drawing health bar and score
    window.draw(*health_outline);
    window.draw(*health_bar);

    window.draw(score_background);
    window.draw(label);
    window.draw(score_text);

    // Saving changes on the screen
    window.display();
}

void Dungeon::adjust_sizes(sf::RenderWindow& window, sf::Event event) {
    float real_height, real_width;

    if (!player->killed()) {
        real_height = current_room->height * tile_size;
        real_width = current_room->width * tile_size;
    } else {
        real_height = GameSprites::SplashScreen.getGlobalBounds().height;
        real_width = GameSprites::SplashScreen.getGlobalBounds().width;
    }

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

    sf::Time delta = timer.restart();
    attack_accumulator += delta;

    while (window.pollEvent(event))
        if (event.type == sf::Event::Resized)
            adjust_sizes(window, event);
        else if (event.type == sf::Event::Closed)
            window.close();
        else
            handle_event(event);

    if (player->killed()) return;

    player->move(delta);

    check_rooms();

    unsigned short vector_len = current_room->enemies.size();

    for (int i = 0; i < vector_len; i++) {
        AbstractEnemy* enemy = current_room->enemies[i];

        if (!enemy->killed()) {
            enemy->ai_move(delta);
        }
    }

    score_text.setString(std::to_string(score));

    if (player->health <= 0) {
        player->is_killed = true;
        player->health = 0;

        event.type = sf::Event::Resized;
        event.size.width = window.getSize().x;
        event.size.height = window.getSize().y;

        if (!offline_mode) {
            sf::Http::Request request("/api/score?k=" + login_token + 
                                      "&i=" + std::to_string(score));

            sf::Http http("http://ydc.exp101t.me");
            http.sendRequest(request);
        }

        adjust_sizes(window, event);
    }

    unsigned short health_bar_height = health_bar->getTextureRect().height;
    unsigned short step = 3;

    health_bar->setTextureRect(
        sf::IntRect(0, 0, step * player->health, health_bar_height)
    );
}

void Dungeon::handle_event(sf::Event event) {
    if (player->killed()) return;

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space)
            attack_enemies();
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
    window.clear();

    window.create(sf::VideoMode(
        current_room->width * tile_size,
        current_room->height * tile_size
    ), "YDC (C) Corgi Industries, 2k19");

    window.setFramerateLimit(60);

    sf::VideoMode screen_size = sf::VideoMode::getDesktopMode();

    window.setPosition(sf::Vector2i(
        (screen_size.width - current_room->width * tile_size) / 2,
        (screen_size.height - current_room->height * tile_size) / 2));

    health_bar = &GameSprites::HealthBar;
    health_outline = &GameSprites::HealthOutline;

    health_outline->setPosition(
        window.getSize().x - health_outline->getTextureRect().width, 0
    );

    health_bar->setPosition(
        health_outline->getPosition() + sf::Vector2f(36, 8)
    );

    font.loadFromFile("Roboto-Regular.ttf");
    
    label.setString("Your score is:");
    label.setFont(font);
    label.setCharacterSize(35);
    label.setPosition(sf::Vector2f(0, 0));
    label.setColor(sf::Color::Black);

    sf::FloatRect bounds = label.getGlobalBounds();

    score_text.setFont(font);
    score_text.setCharacterSize(35);
    score_text.setPosition(sf::Vector2f(bounds.left + bounds.width + 20, 0));
    score_text.setColor(sf::Color::Black);

    score_background.setFillColor(sf::Color::White);
    score_background.setOutlineColor(sf::Color::White);
    score_background.setOutlineThickness(2);
    score_background.setPosition(sf::Vector2f(0, 0));
    score_background.setSize(sf::Vector2f(300, 40));
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

void Dungeon::attack_enemies() {
    if (attack_accumulator < attack_reload_time) return;

    attack_accumulator = sf::Time::Zero;

    unsigned short player_damage = 10;
    float radius = 40.f;

    for (AbstractEnemy* enemy: current_room->enemies) {
        sf::FloatRect enemy_bounds = enemy->get_solid_bounds();
        sf::FloatRect player_bounds = player->get_solid_bounds();

        float player_x = player_bounds.left + player_bounds.width / 2,
              player_y = player_bounds.top + player_bounds.height / 2;

        float enemy_x = enemy_bounds.left + enemy_bounds.width / 2,
              enemy_y = enemy_bounds.top + enemy_bounds.height / 2;

        float distance = std::min(abs(enemy_x - player_x), abs(enemy_y - player_y));

        if (distance <= radius) {
            enemy->health -= player_damage;
        }
    }
}

void Dungeon::set_login_token(std::string token) {
    offline_mode = false;
    login_token = token;
}