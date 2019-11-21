#ifndef YDC_OBJECTS_ENTITIES_PLAYER_HPP_
#define YDC_OBJECTS_ENTITIES_PLAYER_HPP_

#include <SFML/System.hpp>
#include "../../Content.hpp"
#include "../Entity.hpp"

// See: Config.hpp.
namespace YDC
{
    /// The main player.
    class Player : public Entity
    {
    public:
        /// Constructs a new player instance.
        ///
        /// @param content The game content.
        /// @param spriteName The name of the sprite for the player.
        Player(Content& content, const sf::String& spriteName);

        /// Destructs the player instance.
        ~Player();

        /// Handles the movement.
        void handleMovement();

        /// Resets the movement.
        void resetMovement();
    };
}

#endif // YDC_OBJECTS_ENTITIES_PLAYER_HPP_
