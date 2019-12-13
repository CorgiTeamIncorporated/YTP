#include "AnimatedSpriteConfig.hpp"
#include "AnimatedSprite.hpp"
#include "GameSprites.hpp"
#include "Unit.hpp"
#pragma once

class AbstractEnemy: public Unit {
public:
    AbstractEnemy(AnimatedSprite* sprite, Dungeon* dungeon = nullptr, float speed = 0):
        Unit(sprite, dungeon, speed) {};

    virtual void ai_move(sf::Time delta_time) = 0;

    friend class GameRoom;
};