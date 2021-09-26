#include "headers/Player.h"

Player::Player(float x, float y)
{
    this->initVariables();
    this->initShapes();
    this->player.setPosition(x, y);
}

Player::~Player()
{

}

void Player::initVariables()
{
    this->movementSpeed = 10;
    this->health = 3;
}

void Player::initShapes()
{
    this->player.setFillColor(sf::Color(0,147,33,255));
    this->player.setSize(sf::Vector2f(50.f, 50.f));
}

void Player::updateInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&this->player.getGlobalBounds().left >= 0.f)
        this->player.move(-this->movementSpeed, 0.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&this->player.getGlobalBounds().left + this->player.getGlobalBounds().width <= 360.f)
        this->player.move(this->movementSpeed, 0.f);
}

void Player::windowBounds(sf::RenderTarget *target)
{
    sf::Vector2f playerPos = this->player.getPosition();
    if(this->player.getGlobalBounds().left <= 0.f)
        this->player.setPosition(0.f, playerPos.y);
    else if(this->player.getGlobalBounds().left + this->player.getGlobalBounds().width >= target->getSize().x)
        this->player.setPosition(target->getSize().x - this->player.getGlobalBounds().width, playerPos.y);
}

void Player::update(sf::RenderTarget *target)
{
    this->updateInput();
    this->windowBounds(target);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->player);
}

const sf::RectangleShape Player::getShape() const
{
    return this->player;
}