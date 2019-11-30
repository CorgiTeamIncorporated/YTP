#include "SFML/Graphics.hpp"
#include <iostream>
#include <ostream>
#pragma once

template<typename T>
std::ostream& operator<<(std::ostream& stream, sf::Rect<T> rect) {
    stream << "Rect(" << rect.left << ", " << rect.top << ", "
           << rect.width << ", " << rect.height << ");";

    return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, sf::Vector2<T> vector) {
    stream << "Vector2{" << vector.x << ", " << vector.y <<  "};";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, sf::Time time) {
    stream << "Time(" << time.asMilliseconds() << ");";
    return stream;
}