#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include "GUIObject.hpp"

class GUIBlock: public GUIObject {
public:
    GUIBlock(const sf::Vector2f& relativePosition);
    ~GUIBlock();
    void addObject(GUIObject* instance);
    void draw(sf::RenderWindow& window);
    void setAlpha(const sf::Uint8& alpha);

private:
    std::list<GUIObject*> objects_;
    sf::Vector2f relativePosition_;

    const sf::Vector2f calculateAbsolutePosition(sf::RenderWindow& window);
};
