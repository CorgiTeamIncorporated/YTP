#include "Enemies/FireBall.hpp"
#include "Enemies/FireMan.hpp"
#include "Scenes/Dungeon.hpp"
#include "GameSprites.hpp"
#include "Directions.hpp"

void FireMan::ai_move(sf::Time delta_time) {
    if (health <= 0) {
        dungeon_ptr->score += 5;
        is_killed = true; return;
    }

    accumulator += delta_time;

    this->direction = Directions::NullDirection;

    float range = 20.f;

    sf::FloatRect player_bounds = dungeon_ptr->player->get_bounds();
    sf::FloatRect fireman_bounds = sprite->get_bounds();

    float player_x = player_bounds.left + player_bounds.width / 2,
          player_y = player_bounds.top + player_bounds.height / 2;

    float fireman_x = fireman_bounds.left + fireman_bounds.width / 2,
          fireman_y = fireman_bounds.top + fireman_bounds.height / 2;

    float dx = player_x - fireman_x, dy = player_y - fireman_y;

    if (abs(dx) < abs(dy)) {
        if (abs(player_x - fireman_x) <= range) {
            if (player_y < fireman_y) {
                spawn_fireball(Directions::Up);
            } else {
                spawn_fireball(Directions::Down);
            }
        } else if (fireman_x < player_x) {
            this->direction = Directions::Right;
        } else {
            this->direction = Directions::Left;
        }
    } else {
        if (abs(player_y - fireman_y) <= range) {
            if (player_x < fireman_x) {
                spawn_fireball(Directions::Left);
            } else {
                spawn_fireball(Directions::Right);
            }
        } else if (fireman_y < player_y) {
            this->direction = Directions::Down;
        } else {
            this->direction = Directions::Up;
        }
    }

    if (!player_bounds.intersects(fireman_bounds)) {
        this->move(delta_time);
    }

    if (is_throwing) {
        throw_accumulator += delta_time;

        if (throw_accumulator <= throw_animation_time) {
            sprite->set_frame(2);
        } else {
            throw_accumulator = sf::Time::Zero;
            is_throwing = false;
        }
    }
}

void FireMan::spawn_fireball(sf::Vector2f direction) {
    this->direction = direction;

    if (accumulator < reload_time) return;

    accumulator = sf::Time::Zero;

    AnimatedSprite* fireball_sprite = new AnimatedSprite(
        new sf::Sprite(GameSprites::FireBall), &FireBallConfig);

    FireBall* fireball = new FireBall(fireball_sprite);
    fireball->get_sprite().setPosition(get_position());
    fireball->set_direction(direction);

    dungeon_ptr->current_room->add_enemy(fireball);

    is_throwing = true;
}