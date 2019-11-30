#pragma once

#include <SFML/Graphics.hpp>
#include "../Elements/GUIBlock.hpp"
#include "../Elements/GUIButton.hpp"
#include "../Elements/GUISimpleSprite.hpp"
#include "../GameFonts.hpp"
#include "../GameManager.hpp"
#include "AbstractScene.hpp"
#include "Dungeon.hpp"

class MainMenu: public AbstractScene {
public:
    GameManager* game_manager_ptr;
    Dungeon* dungeon_ptr;

    MainMenu();
    void handle_event(sf::Event& event, sf::RenderWindow& window);
    void preload();
    void render(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);

private:
    bool intro_started = false;
    bool intro_fade_in = false;
    bool intro_show = false;
    bool menu_fade_in = false;
    bool menu_show = false;
    sf::Clock anim_timer;
    sf::Uint16 current_alpha = 0;
    GUIBlock block;
    sf::Text startText;
    sf::Text quitText;
    GUIButton start;
    GUIButton quit;
    GUISimpleSprite logo;
};
