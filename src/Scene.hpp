#ifndef YDC_SCENE_HPP_
#define YDC_SCENE_HPP_

#include <SFML/Graphics.hpp>

namespace YDC
{
    /// Forward declare a game content.
    class Content;

    /// A scene - piece of action.
    class Scene
    {
    public:
        /// Constructs a new scene instance.
        ///
        /// @param content The game content.
        Scene(Content& content);

        /// Destructs the scene instance.
        ~Scene();

        /// Runs the scene action.
        ///
        /// @param window The window handler.
        virtual void run(sf::RenderWindow& window) = 0;

    protected:
        /// The game content reference.
        Content& content_;

        /// The state function name.
        sf::String state_ = "Initial";
    };
} // YGC

#endif // YDC_SCENE_HPP_
