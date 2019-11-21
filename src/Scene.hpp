#ifndef YDC_SCENE_HPP_
#define YDC_SCENE_HPP_

#include <map>
#include <SFML/Graphics.hpp>

// See: Config.hpp.
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
        void run(sf::RenderWindow& window);

    protected:
        /// The current act type definition.
        typedef void (Scene::*Act)(sf::RenderWindow& window);

        /// The game content reference.
        Content& content_;

        /// Sets the current act.
        ///
        /// @param pointer The pointer to the act.
        void setCurrentAct(Act pointer);

    private:
        /// The current act of the scene.
        Act currentAct_;
    };
}

#endif // YDC_SCENE_HPP_
