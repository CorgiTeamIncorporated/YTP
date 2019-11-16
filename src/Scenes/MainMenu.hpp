#ifndef YDC_SCENES_MAINMENU_HPP_
#define YDC_SCENES_MAINMENU_HPP_

#include <SFML/Graphics.hpp>
#include "../Animations/Fade.hpp"
#include "../Objects/Background.hpp"
#include "../Objects/Button.hpp"
#include "../Content.hpp"
#include "../Scene.hpp"

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

        /// Shows the main menu.
        ///
        /// @param window The window handler.
        void run(sf::RenderWindow& window);

    private:
        /// The background.
        Background background_;

        /// The background fade.
        Fade backgroundFade_;

        /// The quit game button text.
        sf::Text quitButtonText_;

        /// The quit game button.
        Button quitButton_;

        /// Fades in the background.
        ///
        /// @param window The window handler.
        void fadeInBackground(sf::RenderWindow& window);

        /// Fades in the buttons.
        ///
        /// @param window The window handler.
        void fadeInButtons(sf::RenderWindow& window);
    };
} // YDC

#endif // YDC_SCENES_MAINMENU_HPP_
