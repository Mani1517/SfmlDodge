#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

class Enemy{
private:
    sf::RectangleShape shape;

    float fallSpeed;
    int randPosition;

    void initVariables();
    void initShapes();
public:
    Enemy(float x = 0.f, float y = 0.f);
    virtual ~Enemy();

    const sf::RectangleShape getShape() const;

    
    void render(sf::RenderTarget *target);
    void update();
    bool destroyWindow();
};