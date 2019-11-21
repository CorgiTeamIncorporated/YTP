#ifndef YDC_OBJECTS_ENTITY_HPP_
#define YDC_OBJECTS_ENTITY_HPP_

#include <SFML/Graphics.hpp>
#include "../Config.hpp"
#include "../Content.hpp"
#include "../Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// The entity on the tile map - player, enemy, etc.
    class Entity : public Object
    {
    public:
        /// Constructs a new entity instance.
        ///
        /// @param content The game content.
        /// @param spriteName The name of the sprite for the entity.
        Entity(Content& content, const sf::String& spriteName);

        /// Destructs the entity instance.
        ~Entity();

        /// Draws the entity.
        ///
        /// @param window The window handler.
        void draw(sf::RenderWindow& window);

        /// Gets whether the entity expects to move.
        ///
        /// @return Whether the entity expects to move.
        bool expectMove() const;

        /// Fetches the state the entity should be in.
        ///
        /// @return The state.
        sf::Uint8 fetchState() const;

        /// Gets the initial position value.
        ///
        /// @return The initial position value.
        sf::Vector2f getInitialPosition() const;

        /// Gets the collisions rectangle.
        ///
        /// @return The rectangle.
        sf::IntRect getRect() const;

        /// Gets the state the entity should be in.
        ///
        /// @return The state.
        sf::Uint8 getState() const;

        /// Gets the step the entity should be in.
        ///
        /// @return The step.
        sf::Uint8 getStep() const;

        /// Handles the movement.
        virtual void handleMovement() = 0;

        /// Resets the movement.
        virtual void resetMovement() = 0;

        /// Sets the alpha color value of the entity.
        ///
        /// @param alpha The alpha color value.
        void setAlpha(const sf::Uint8& alpha);

        /// Sets the state the entity is in.
        ///
        /// @param state The state.
        void setState(const sf::Uint8& state);

        /// Sets the step the entity is in.
        ///
        /// @param step The step.
        void setStep(const sf::Uint8& step);

    protected:
        /// Whether the forward key is triggered.
        bool eventForwardTriggered_ = false;

        /// Whether the backward event is triggered.
        bool eventBackwardTriggered_ = false;

        /// Whether the left key is triggered.
        bool eventLeftTriggered_ = false;

        /// Whether the right key is triggered.
        bool eventRightTriggered_ = false;

        /// The sprite positions.
        sf::IntRect positions_[16] =
        {
            /// The still front.
            sf::IntRect(ENTITY_WIDTH * 0, ENTITY_HEIGHT * 0, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The first step frame front.
            sf::IntRect(ENTITY_WIDTH * 1, ENTITY_HEIGHT * 0, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The second step frame front.
            sf::IntRect(ENTITY_WIDTH * 2, ENTITY_HEIGHT * 0, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The third step frame front.
            sf::IntRect(ENTITY_WIDTH * 3, ENTITY_HEIGHT * 0, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The still back.
            sf::IntRect(ENTITY_WIDTH * 0, ENTITY_HEIGHT * 3, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The first step frame back.
            sf::IntRect(ENTITY_WIDTH * 1, ENTITY_HEIGHT * 3, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The second step frame back.
            sf::IntRect(ENTITY_WIDTH * 2, ENTITY_HEIGHT * 3, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The third step frame back.
            sf::IntRect(ENTITY_WIDTH * 3, ENTITY_HEIGHT * 3, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The still left.
            sf::IntRect(ENTITY_WIDTH * 0, ENTITY_HEIGHT * 1, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The first step frame left.
            sf::IntRect(ENTITY_WIDTH * 1, ENTITY_HEIGHT * 1, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The second step frame left.
            sf::IntRect(ENTITY_WIDTH * 2, ENTITY_HEIGHT * 1, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The third step frame left.
            sf::IntRect(ENTITY_WIDTH * 3, ENTITY_HEIGHT * 1, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The still right.
            sf::IntRect(ENTITY_WIDTH * 0, ENTITY_HEIGHT * 2, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The first step frame right.
            sf::IntRect(ENTITY_WIDTH * 1, ENTITY_HEIGHT * 2, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The second step frame right.
            sf::IntRect(ENTITY_WIDTH * 2, ENTITY_HEIGHT * 2, ENTITY_WIDTH, ENTITY_HEIGHT),

            /// The third step frame right.
            sf::IntRect(ENTITY_WIDTH * 3, ENTITY_HEIGHT * 2, ENTITY_WIDTH, ENTITY_HEIGHT),
        };

        /// The collision rectangle.
        sf::IntRect rect_ = sf::IntRect(0, ENTITY_HEIGHT / 5 * 4, ENTITY_WIDTH, ENTITY_HEIGHT / 5);

        /// The entity size.
        sf::Vector2f size_;

        /// The sprite copy.
        sf::Sprite sprite_;

        /// The state the entity is in (0 to 3: front, back, left, right).
        sf::Uint8 state_ = 0;

        /// The step condition (0 to 3: still, first, second, third).
        sf::Uint8 step_ = 0;

        /// Sets the sprite position.
        void setSpritePosition();
    };
}

#endif // YDC_OBJECTS_ENTITY_HPP_
