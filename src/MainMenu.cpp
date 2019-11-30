#include "Scenes/MainMenu.hpp"
#include "GameSprites.hpp"

MainMenu::MainMenu():
        AbstractScene(),
        block(sf::Vector2f(50, 50)),
        startText("Start the Game", GameFonts::Default),
        quitText("Quit the Game", GameFonts::Default),
        start(startText),
        quit(quitText),
        logo(GameSprites::Logo) {
    logo.setLocalPosition(sf::Vector2f(0, -100));
    start.setLocalPosition(sf::Vector2f(0, 0));
    quit.setLocalPosition(sf::Vector2f(0, 100));
    block.addObject(&logo);
    block.addObject(&start);
    block.addObject(&quit);
}

void MainMenu::handle_event(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Resized) {
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
    }
}

void MainMenu::preload() {}

void MainMenu::render(sf::RenderWindow& window) {
    GameSprites::Corgi.setPosition(sf::Vector2f(window.getSize().x / 100.0f * 50, window.getSize().y / 100.0f * 50));
    GameSprites::MenuBG.setTextureRect(sf::IntRect(0, 0, (int)window.getSize().x, (int)window.getSize().y));

    if (!intro_fade_in || !intro_show) {
        window.draw(GameSprites::Corgi);
        return;
    }

    if (!menu_fade_in) {
        window.draw(GameSprites::Corgi);
        window.draw(GameSprites::MenuBG);
        block.draw(window);
        return;
    }

    if (!menu_show) {
        window.draw(GameSprites::Corgi);
        window.draw(GameSprites::MenuBG);
        block.draw(window);
        return;
    }

    game_manager_ptr->set_scene(dungeon_ptr);
}

void MainMenu::update(sf::RenderWindow& window) {
    if (!intro_started) {
        GameSprites::Corgi.setOrigin(GameSprites::Corgi.getTexture()->getSize().x / 2, GameSprites::Corgi.getTexture()->getSize().y / 2);
        intro_started = true;
        anim_timer.restart();
    }

    if (!intro_fade_in) {
        current_alpha = 255 * (anim_timer.getElapsedTime() / sf::seconds(1.5));

        if (current_alpha >= 255) {
            current_alpha = 255;
            intro_fade_in = true;
            anim_timer.restart();
        }

        GameSprites::Corgi.setColor(sf::Color(255, 255, 255, current_alpha));
        return;
    }

    if (!intro_show) {
        if (anim_timer.getElapsedTime() > sf::seconds(2)) {
            intro_show = true;
            current_alpha = 0;
            anim_timer.restart();
        }

        return;
    }

    if (!menu_fade_in) {
        current_alpha = 255 * (anim_timer.getElapsedTime() / sf::seconds(1.5));

        if (current_alpha >= 255) {
            current_alpha = 255;
            menu_fade_in = true;
            anim_timer.restart();
        }

        GameSprites::MenuBG.setColor(sf::Color(255, 255, 255, current_alpha));
        block.setAlpha(current_alpha);
        return;
    }

    if (!menu_show) {
        if (quit.getClicked()) {
            window.close();
            return;
        }

        if (start.getClicked()) {
            menu_show = true;
            anim_timer.restart();
        }

        return;
    }
}
