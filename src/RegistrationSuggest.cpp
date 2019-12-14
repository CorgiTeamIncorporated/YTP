#include "GameRoom.hpp"
#include "GameSprites.hpp"
#include "MapBuilder.hpp"
#include "Scenes/Dungeon.hpp"
#include "GameManager.hpp"
#include "Enemies/Zombie.hpp"
#include "Enemies/Spikes.hpp"
#include "Enemies/FireBall.hpp"
#include "Enemies/FireMan.hpp"

#include "Scenes/RegistrationSuggest.hpp"
#include "SFML/Network.hpp"
#include <windows.h>
#include <ShellApi.h>
#include <string>
#include <iostream>

GameRoom* get_test_room(Dungeon* dungeon) {
    MapBuilder* mapBuilder = new MapBuilder(10, 20, dungeon);
    mapBuilder->buildMap();
    GameRoom* room = mapBuilder->getStartRoom();

    return room;
}

void RegistrationSuggest::generate_token() {
    sf::Http::Request request("/api/key");
    sf::Http http("http://ydc.exp101t.me");

    sf::Http::Response response = http.sendRequest(request);

    login_token = response.getBody();
}

void RegistrationSuggest::preload(sf::RenderWindow& window) {
    setup(window);
}

void RegistrationSuggest::setup(sf::RenderWindow& window) {
    unsigned short button_width = 400;
    unsigned short button_height = 50;
    unsigned short spacer = 50;

    unsigned short x = (window.getSize().x - button_width) / 2;
    unsigned short y = (window.getSize().y - spacer - 2 * button_height) / 2;

    font.loadFromFile("Roboto-Regular.ttf");

    offline_text.setFont(font);
    offline_text.setString(sf::String("Play offline"));
    offline_text.setCharacterSize(30);
    offline_text.setColor(sf::Color::Black);
    offline_text.setStyle(sf::Text::Regular);

    sf::FloatRect text_bounds = offline_text.getLocalBounds();

    offline_text.setPosition(
        sf::Vector2f(x + (button_width - text_bounds.width) / 2,
                     y + (button_height - text_bounds.height) / 2));

    offline_button.setPosition(sf::Vector2f(x, y));
    offline_button.setSize(sf::Vector2f(button_width, button_height));
    offline_button.setFillColor(sf::Color(255, 255, 255));
    offline_button.setOutlineColor(sf::Color(0, 0, 0));
    offline_button.setOutlineThickness(2.0);

    y += button_height + spacer;

    online_button.setPosition(sf::Vector2f(x, y));
    online_button.setSize(sf::Vector2f(button_width, button_height));
    online_button.setFillColor(sf::Color(255, 255, 255));
    online_button.setOutlineColor(sf::Color(0, 0, 0));
    online_button.setOutlineThickness(2.0);

    online_text.setFont(font);
    online_text.setString(sf::String("Log in / register"));
    online_text.setCharacterSize(30);
    online_text.setColor(sf::Color::Black);
    online_text.setStyle(sf::Text::Regular);

    text_bounds = online_text.getLocalBounds();

    online_text.setPosition(
        sf::Vector2f(x + (button_width - text_bounds.width) / 2,
                     y + (button_height - text_bounds.height) / 2));
}

void RegistrationSuggest::update(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::FloatRect mouse_rect = sf::FloatRect(
                event.mouseButton.x, event.mouseButton.y, 1, 1);

            if (mouse_rect.intersects(online_button.getGlobalBounds())) {
                // Opens that window in browser
                generate_token();

                std::string short_byte_url = "https://ydc.exp101t.me/login?k=" + login_token;
                std::wstring url = std::wstring(short_byte_url.begin(), short_byte_url.end());

                ShellExecuteW(0, 0, url.c_str(), NULL, NULL, SW_SHOW);
            } else if (mouse_rect.intersects(offline_button.getGlobalBounds())) {
                start_game(window, true);
            }
        }
    }

    if (check_if_logged()) {
        start_game(window, false, login_token);
    }
}

bool RegistrationSuggest::check_if_logged() {
    sf::Http::Request request("/api/check?k=" + login_token);
    sf::Http http("http://ydc.exp101t.me");

    sf::Http::Response response = http.sendRequest(request);

    return response.getBody() == "ok";
}

void RegistrationSuggest::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    window.draw(offline_button);
    window.draw(online_button);
    window.draw(offline_text);
    window.draw(online_text);

    window.display();
}

void RegistrationSuggest::start_game(sf::RenderWindow& window, bool offline_mode, std::string token) {
    GameSprites::init_sprites();

    unsigned int tile_size = 100;
    unsigned int width = 11, height = 9;

    AnimatedSprite* player_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::Player), &SkeletonConfig);

    Unit* player = new Unit(player_sprite);
    player->set_speed(0.5);
    player->set_solid_height(30);
    player->get_sprite().setPosition(tile_size, tile_size);

    Dungeon* dungeon = new Dungeon;
    GameRoom* main_room = get_test_room(dungeon);

    dungeon->set_player(player);
    dungeon->set_room(main_room);
    dungeon->set_tile_size(tile_size);

    if (!offline_mode)
        dungeon->set_login_token(token);

    manager->set_scene(dungeon);
}