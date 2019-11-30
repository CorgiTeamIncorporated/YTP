#include "GameFonts.hpp"

namespace GameFonts {
    // namespace Dungeon {
        sf::Font Default;
    // }
}

void GameFonts::init() {
    Default.loadFromFile("fonts/alata.ttf");
}
