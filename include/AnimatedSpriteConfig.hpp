#include <SFML/Graphics.hpp>
#include <vector>
#pragma once

struct AnimatedSpriteConfig {
    std::vector<sf::IntRect> left_moves;
    std::vector<sf::IntRect> right_moves;
    std::vector<sf::IntRect> up_moves;
    std::vector<sf::IntRect> down_moves;
    unsigned short move_frames_count;
};

const AnimatedSpriteConfig PlayerConfig = {
    {sf::IntRect(0, 48, 32, 48), sf::IntRect(32, 48, 32, 48),
     sf::IntRect(64, 48, 32, 48), sf::IntRect(96, 48, 32, 48)},
    {sf::IntRect(0, 96, 32, 48), sf::IntRect(32, 96, 32, 48),
     sf::IntRect(64, 96, 32, 48), sf::IntRect(96, 96, 32, 48)},
    {sf::IntRect(0, 144, 32, 48), sf::IntRect(32, 144, 32, 48),
     sf::IntRect(64, 144, 32, 48), sf::IntRect(96, 144, 32, 48)},
    {sf::IntRect(0, 0, 32, 48), sf::IntRect(32, 0, 32, 48),
     sf::IntRect(64, 0, 32, 48), sf::IntRect(96, 0, 32, 48)}, 4
};