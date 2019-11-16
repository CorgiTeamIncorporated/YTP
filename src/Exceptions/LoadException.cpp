#include "LoadException.hpp"

YDC::LoadException::LoadException() :
    std::runtime_error("Cannot load an unknown content piece.")
{
}

YDC::LoadException::LoadException(const sf::String& path) :
    std::runtime_error(("Cannot load a content piece at path " + path + ".").toAnsiString().c_str())
{
}

YDC::LoadException::~LoadException() noexcept
{
}
