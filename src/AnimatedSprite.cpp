#include "AnimatedSprite.hpp"
#include "Directions.hpp"

AnimatedSprite::AnimatedSprite(sf::Sprite* sprite, const AnimatedSpriteConfig* config) {
    this->last_direct = Directions::Down;
    this->sprite = sprite;
    this->config = config;
    this->frame_num = 0;
    this->sprite->setTextureRect(config->down_moves.at(0));
}

void AnimatedSprite::move(const sf::Vector2f delta) {
    if (delta == last_direct) {
        frame_num = (frame_num + 1) % config->move_frames_count;
    } else {
        last_direct = delta;
        frame_num = 0;
    }

    sprite->move(delta); 

    if (delta == Directions::Left) {
        sprite->setTextureRect(config->left_moves.at(frame_num));
    } else if (delta == Directions::Right) {
        sprite->setTextureRect(config->right_moves.at(frame_num));
    } else if (delta == Directions::Up) {
        sprite->setTextureRect(config->up_moves.at(frame_num));
    } else {
        sprite->setTextureRect(config->down_moves.at(frame_num));
    }
}

sf::Sprite& AnimatedSprite::get_sprite() {
    return *sprite;
}