#include "Enemies/AbstractEnemy.hpp"
#pragma once

class Zombie: public AbstractEnemy {
public:
    Zombie(AnimatedSprite* sprite, Dungeon* dungeon = nullptr):
        AbstractEnemy(sprite, dungeon, 0.2) {
            this->health = 30;
        };

    Zombie(Dungeon* dungeon = nullptr):
        AbstractEnemy(new AnimatedSprite(
            new sf::Sprite(GameSprites::Zombie), &ZombieConfig), dungeon, 0.2) {
                this->health = 30;
            };

    void ai_move(sf::Time delta_time);

    sf::Time attack_accumulator = sf::Time::Zero;
    sf::Time attack_reload_time = sf::seconds(1);
};