#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    Object();
    Object(const sf::Vector2f& position);
    ~Object();
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::Uint8 getInitialAlpha() const;
    virtual sf::Vector2f getInitialPosition() const;
    sf::Vector2f getLocalPosition() const;
    sf::Vector2f getPosition() const;
    virtual void setAlpha(const sf::Uint8& alpha);
    virtual void setLocalPosition(const sf::Vector2f& localPosition);
    virtual void setPosition(const sf::Vector2f& position);

protected:
    sf::Vector2f position_ = sf::Vector2f(0, 0);
    sf::Vector2f localPosition_ = sf::Vector2f(0, 0);
};
