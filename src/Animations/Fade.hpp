#ifndef YDC_ANIMATIONS_FADE_HPP_
#define YDC_ANIMATIONS_FADE_HPP_

#include <SFML/Graphics.hpp>
#include "../Animation.hpp"
#include "../Object.hpp"

// See: Config.hpp.
namespace YDC
{
    /// Fade-in and fade-out animations.
    class Fade : public Animation
    {
    public:
        /// Constructs a new fade animation instance for an object.
        ///
        /// @param object The object to fade in/out.
        Fade(Object& object);

        /// Constructs a new fade animation instance for an object.
        ///
        /// @param object The object to fade in/out.
        /// @param inOut Whether the animation is fade-in or fade-out.
        Fade(Object& object, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha);

        /// Constructs a new fade animation instance for an object.
        ///
        /// @param object The object to fade in/out.
        /// @param time The time required to finish the animation.
        Fade(Object& object, const sf::Time& time);

        /// Constructs a new fade animation instance for an object.
        ///
        /// @param object The object to fade in/out.
        /// @param time The time required to finish the animation.
        /// @param inOut Whether the animation is fade-in or fade-out.
        Fade(Object& object, const sf::Time& time, const sf::Uint8 startAlpha, const sf::Uint8 endAlpha);

        /// Destructs the fade animation instance.
        ~Fade();

        /// Draws the sprite/shape animated.
        ///
        /// @param window The window handler.
        void drawObject(sf::RenderWindow& window);

        /// Gets whether the animation is done.
        ///
        /// @return Whether the animation is done.
        bool getDone() const;

        /// Resets the style of the animated object.
        void resetObject();

    private:
        /// The end aplha color value.
        const sf::Uint8 endAlpha_ = 255;

        /// The start alpha color value.
        const sf::Uint8 startAlpha_ = 0;

        /// Gets the current alpha value to draw.
        ///
        /// @return The alpha value.
        sf::Uint8 getCurrentAlpha() const;

        /// Gets the current alpha value, but with error in need to be corrected.
        ///
        /// @return The alpha value with error.
        sf::Int16 getCurrentAlphaWithError() const;
    };
}

#endif // YDC_ANIMATIONS_FADE_HPP_
