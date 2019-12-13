#include "Enemies/AbstractEnemy.hpp"
#pragma once

class FireMan: public AbstractEnemy {
private:
    bool is_throwing = false;
public:
    FireMan(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        AbstractEnemy(sprite, dungeon, 0.3) {
            this->health = 200;
        };

    FireMan(Dungeon* dungeon = nullptr):
        AbstractEnemy(new AnimatedSprite(
            new sf::Sprite(GameSprites::FireMan), &FireManConfig), dungeon, 0.3) {
                this->health = 200;
            };

    void spawn_fireball(sf::Vector2f direction);
    void ai_move(sf::Time delta_time);

    sf::Time throw_animation_time = sf::milliseconds(500);
    sf::Time throw_accumulator = sf::Time::Zero;

    sf::Time reload_time = sf::seconds(1);
    sf::Time accumulator = sf::Time::Zero;
};