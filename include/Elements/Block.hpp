#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Block : public Object {
public:
    Block(const sf::Vector2f& relativePosition);
    ~Block();
    void addObject(Object* instance);
    void draw(sf::RenderWindow& window);
    void setAlpha(const sf::Uint8& alpha);

private:
    std::list<Object*> objects_;
    sf::Vector2f relativePosition_;

    const sf::Vector2f calculateAbsolutePosition(sf::RenderWindow& window);
};
