#ifndef YDC_EXCEPTIONS_LOADEXCEPTION_HPP_
#define YDC_EXCEPTIONS_LOADEXCEPTION_HPP_

#include <stdexcept>
#include <SFML/System.hpp>

// See: Config.hpp.
namespace YDC
{
    /// A content loading exception.
    class LoadException : public std::runtime_error
    {
    public:
        /// Constructs a new exception instance with no content path.
        LoadException();

        /// Constructs a new exception instance with the content path.
        ///
        /// @param path The path to the content.
        LoadException(const sf::String& path);

        /// Destructs the exception instance.
        ~LoadException() noexcept;
    };
}

#endif // YDC_EXCEPTIONS_LOADEXCEPTION_HPP_
