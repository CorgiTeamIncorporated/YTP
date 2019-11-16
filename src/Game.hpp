#ifndef YDC_GAME_HPP_
#define YDC_GAME_HPP_

#include <exception>
#include "Content.hpp"
#include "Window.hpp"

namespace YDC
{
    /// A common game start point.
    class Game
    {
    public:
        /// Constructs a new game instance.
        Game();

        /// Destructs the game instance.
        ~Game();

        /// Handles any exceptions risen during `handleInitialization`.
        ///
        /// @param exception The exception to handle.
        void handleException(const std::exception& exception) const noexcept;

        /// Handles the game initialization.
        void handleInitialization();

    private:
        /// The game content.
        Content content_;

        /// The window.
        Window window_;
    };
} // YDC

#endif // YDC_GAME_HPP_
