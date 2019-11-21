#ifndef YDC_SCENES_LOADSCREEN_HPP_
#define YDC_SCENES_LOADSCREEN_HPP_

#include <thread>
#include <SFML/Graphics.hpp>
#include "../Content.hpp"
#include "../Scene.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A load screen, the first thing a user sees.
    class LoadScreen : public Scene
    {
    public:
        /// Constructs a new load screen instance.
        ///
        /// @param content The game content.
        LoadScreen(Content& content);

        /// Destructs the load screen instance.
        ~LoadScreen();

        /// Changes the scene to the main menu.
        ///
        /// @param window The window handler.
        void changeToMainMenu(sf::RenderWindow& window);

        /// Shows the load screen.
        ///
        /// @param window The window handler.
        void checkThread(sf::RenderWindow& window);

        /// Loads the game in the separate thread.
        void loadGame();

    private:
        /// Whether the game is loaded.
        bool loaded_ = false;

        /// The game load thread.
        std::thread thread_;
    };
}

#endif // YDC_SCENES_LOADSCREEN_HPP_
