#include "AnimatedSprite.hpp"
#include "Directions.hpp"
#include "debug.hpp"

AnimatedSprite::AnimatedSprite(sf::Sprite* sprite, const AnimatedSpriteConfig* config) {
    this->last_direct = Directions::Down;
    this->sprite = sprite;
    this->config = config;
    this->frame_num = 0;
    this->time_accumulator = sf::Time::Zero;
    this->sprite->setTextureRect(config->down_moves.at(0));
}

void AnimatedSprite::move(const sf::Vector2f delta, float speed, sf::Time delta_time) {
    if (delta == last_direct) {
        if (time_accumulator >= config->frame_rate_time) {
            frame_num = (frame_num + 1) % config->move_frames_count;
            time_accumulator -= config->frame_rate_time;
        }
    } else {
        last_direct = delta;
        frame_num = 0;
    }

    time_accumulator += delta_time;

    float time_as_float = static_cast<float>(delta_time.asMicroseconds());

    sprite->move(delta * speed * time_as_float * static_cast<float>(1e-3)); 
    // Why not just to take milliseconds? It's 'cause of rounding of floats
    // If delta_time is quite small, player starts to move very slowly

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

sf::FloatRect AnimatedSprite::get_bounds() {
    return sprite->getGlobalBounds();
}

sf::Vector2f AnimatedSprite::get_position() {
    return sprite->getPosition();
}

void AnimatedSprite::set_position(sf::Vector2f position) {
    sprite->setPosition(position);
}