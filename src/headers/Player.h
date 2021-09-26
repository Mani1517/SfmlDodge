#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player{
private:
    sf::RectangleShape player;

    float movementSpeed;

    void initVariables();
    void initShapes();

public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    const sf::RectangleShape getShape() const;
    int health;

    void windowBounds(sf::RenderTarget *target);
    void updateInput();
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
};