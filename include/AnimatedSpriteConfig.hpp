#include <SFML/Graphics.hpp>
#include <vector>
#pragma once

struct AnimatedSpriteConfig {
    std::vector<sf::IntRect> left_moves;
    std::vector<sf::IntRect> right_moves;
    std::vector<sf::IntRect> up_moves;
    std::vector<sf::IntRect> down_moves;
    unsigned short move_frames_count;
    sf::Time frame_rate_time;
};

const AnimatedSpriteConfig PlayerConfig = {
    {sf::IntRect(0, 48, 32, 48), sf::IntRect(32, 48, 32, 48),
     sf::IntRect(64, 48, 32, 48), sf::IntRect(96, 48, 32, 48)},
    {sf::IntRect(0, 96, 32, 48), sf::IntRect(32, 96, 32, 48),
     sf::IntRect(64, 96, 32, 48), sf::IntRect(96, 96, 32, 48)},
    {sf::IntRect(0, 144, 32, 48), sf::IntRect(32, 144, 32, 48),
     sf::IntRect(64, 144, 32, 48), sf::IntRect(96, 144, 32, 48)},
    {sf::IntRect(0, 0, 32, 48), sf::IntRect(32, 0, 32, 48),
     sf::IntRect(64, 0, 32, 48), sf::IntRect(96, 0, 32, 48)}, 4,
    sf::milliseconds(10000)
};

const AnimatedSpriteConfig SkeletonConfig = {
    {sf::IntRect(0, 0, 50, 75), sf::IntRect(50, 0, 50, 75),
     sf::IntRect(100, 0, 50, 75), sf::IntRect(150, 0, 50, 75)},
    {sf::IntRect(0, 0, 50, 75), sf::IntRect(50, 0, 50, 75),
     sf::IntRect(100, 0, 50, 75), sf::IntRect(150, 0, 50, 75)},
    {sf::IntRect(0, 0, 50, 75), sf::IntRect(50, 0, 50, 75),
     sf::IntRect(100, 0, 50, 75), sf::IntRect(150, 0, 50, 75)},
    {sf::IntRect(0, 0, 50, 75), sf::IntRect(50, 0, 50, 75),
     sf::IntRect(100, 0, 50, 75), sf::IntRect(150, 0, 50, 75)}, 4,
    sf::milliseconds(100)
};

const AnimatedSpriteConfig ZombieConfig = {
    {sf::IntRect(0, 48, 32, 48), sf::IntRect(32, 48, 32, 48),
     sf::IntRect(64, 48, 32, 48), sf::IntRect(96, 48, 32, 48)},
    {sf::IntRect(0, 96, 32, 48), sf::IntRect(32, 96, 32, 48),
     sf::IntRect(64, 96, 32, 48), sf::IntRect(96, 96, 32, 48)},
    {sf::IntRect(0, 144, 32, 48), sf::IntRect(32, 144, 32, 48),
     sf::IntRect(64, 144, 32, 48), sf::IntRect(96, 144, 32, 48)},
    {sf::IntRect(0, 0, 32, 48), sf::IntRect(32, 0, 32, 48),
     sf::IntRect(64, 0, 32, 48), sf::IntRect(96, 0, 32, 48)}, 4,
    sf::milliseconds(100)
};

const AnimatedSpriteConfig SpikesConfig = {
    {sf::IntRect(0, 0, 100, 100), sf::IntRect(100, 0, 100, 100)},
    {sf::IntRect(0, 0, 100, 100), sf::IntRect(100, 0, 100, 100)},
    {sf::IntRect(0, 0, 100, 100), sf::IntRect(100, 0, 100, 100)},
    {sf::IntRect(0, 0, 100, 100), sf::IntRect(100, 0, 100, 100)},
    2, sf::Time::Zero
};

const AnimatedSpriteConfig FireBallConfig = {
    {sf::IntRect(0, 100, 100, 50)}, {sf::IntRect(0, 150, 100, 50)},
    {sf::IntRect(25, 200, 50, 100)}, {sf::IntRect(25, 0, 50, 100)},
    1, sf::seconds(1)
};

/*
const AnimatedSpriteConfig FireBallConfig = {
    {sf::IntRect(0, 200, 200, 100)}, {sf::IntRect(0, 300, 200, 100)},
    {sf::IntRect(50, 400, 100, 200)}, {sf::IntRect(50, 0, 100, 200)},
    1, sf::Time::Zero
};
*/

const AnimatedSpriteConfig FireManConfig = {
    {sf::IntRect(0, 120, 90, 120), sf::IntRect(90, 120, 90, 120), sf::IntRect(180, 120, 90, 120)},
    {sf::IntRect(0, 240, 90, 120), sf::IntRect(90, 240, 90, 120), sf::IntRect(180, 240, 90, 120)},
    {sf::IntRect(0, 360, 90, 120), sf::IntRect(90, 360, 90, 120), sf::IntRect(180, 360, 90, 120)},
    {sf::IntRect(0, 0, 90, 120), sf::IntRect(90, 0, 90, 120), sf::IntRect(180, 0, 90, 120)},
    2, sf::milliseconds(100)
};