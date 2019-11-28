#include "AnimatedSpriteConfig.hpp"
#pragma once

class AnimatedSprite {
private:
    const AnimatedSpriteConfig* config;
    sf::Time time_accumulator;
    sf::Vector2f last_direct;
    unsigned short frame_num;
    sf::Sprite* sprite;
public:
    AnimatedSprite(sf::Sprite* sprite, const AnimatedSpriteConfig* config);
    void move(const sf::Vector2f delta, float speed, sf::Time delta_time);
    sf::Sprite& get_sprite();
};