#ifndef YDC_SCENES_MAINMENU_HPP_
#define YDC_SCENES_MAINMENU_HPP_

#include <SFML/Graphics.hpp>
#include "../Animations/Fade.hpp"
#include "../Objects/Background.hpp"
#include "../Objects/Block.hpp"
#include "../Objects/Button.hpp"
#include "../Content.hpp"
#include "../Scene.hpp"

// See: Config.hpp.
namespace YDC
{
    /// A main menu.
    class MainMenu : public Scene
    {
    public:
        /// Constructs a new the main menu instance.
        ///
        /// @param content The game content.
        MainMenu(Content& content);

        /// Destructs the main menu instance.
        ~MainMenu();

        /// Fades in the background.
        ///
        /// @param window The window handler.
        void fadeInBackground(sf::RenderWindow& window);

        /// Fades in the buttons.
        ///
        /// @param window The window handler.
        void fadeInButtons(sf::RenderWindow& window);

        /// Fades out the screen and moves on to the game.
        ///
        /// @param window The window handler.
        void fadeOut(sf::RenderWindow& window);

        /// Stands by on the menu screen.
        ///
        /// @param window The window handler.
        void standBy(sf::RenderWindow& window);

    private:
        /// The background.
        Background background_;

        /// The background fade-in.
        Fade backgroundFadeIn_;

        /// The background fade-out.
        Fade backgroundFadeOut_;

        /// The main menu primary block.
        Block block_;

        /// The primary block fade-in.
        Fade blockFadeIn_;

        /// The primary block fade-out.
        Fade blockFadeOut_;

        /// The start game button text.
        sf::Text startButtonText_;

        /// The start game button.
        Button startButton_;

        /// The quit game button text.
        sf::Text quitButtonText_;

        /// The quit game button.
        Button quitButton_;
    };
}

#endif // YDC_SCENES_MAINMENU_HPP_
