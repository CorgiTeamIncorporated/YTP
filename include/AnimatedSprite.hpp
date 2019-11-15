#include "AnimatedSpriteConfig.hpp"
#pragma once

class AnimatedSprite {
private:
    const AnimatedSpriteConfig* config;
    sf::Vector2f last_direct;
    unsigned short frame_num;
    sf::Sprite* sprite;
public:
    AnimatedSprite(sf::Sprite* sprite, const AnimatedSpriteConfig* config);
    void move(const sf::Vector2f delta, float speed);
    sf::Sprite& get_sprite();
};