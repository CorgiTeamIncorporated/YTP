#ifndef YDC_EXCEPTIONS_LOADEXCEPTION_HPP_
#define YDC_EXCEPTIONS_LOADEXCEPTION_HPP_

#include <stdexcept>
#include <SFML/System.hpp>

namespace YDC
{
    /// A content loading exception.
    class LoadException : public std::runtime_error
    {
    public:
        /// Constructs an exception with no content path.
        LoadException();

        /// Constructs an exception with the content path.
        ///
        /// @param path The path to the content.
        LoadException(const sf::String& path);

        /// Destructs the exception.
        ~LoadException() noexcept;
    };
} // YDC

#endif // YDC_EXCEPTIONS_LOADEXCEPTION_HPP_
