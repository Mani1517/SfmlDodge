#include "headers/Enemy.h"

Enemy::Enemy(float x, float y)
{
    this->initVariables();
    this->initShapes();
    
    this->shape.setPosition(x, y);
}

Enemy::~Enemy()
{}

void Enemy::initShapes()
{
    this->shape.setSize(sf::Vector2f(40.f, 40.f));
    this->shape.setFillColor(sf::Color::Red);
}

void Enemy::initVariables()
{
    this->fallSpeed = 5;
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Enemy::update()
{
    this->shape.move(0.f, fallSpeed);
}

bool Enemy::destroyWindow()
{
    if((this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height) >= (640 + 40))return true;
    return false;
}

const sf::RectangleShape Enemy::getShape() const
{
    return this->shape;
}