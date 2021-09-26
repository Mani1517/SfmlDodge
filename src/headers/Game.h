#pragma once

#include "Player.h"
#include "Enemy.h"

#include <list>
#include <iostream>
#include <sstream>

class Game{
private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Clock clock;
    sf::Text guiText;
    sf::Text healthText;
    sf::Font font;
    
    Player player;
    Enemy enemy;

    std::list<Enemy>enemyLst;
    std::list<Enemy>::iterator iter;

    float delay;
    bool endGame;
    float randNum;
    int score;
    bool dead;

    void InitVariable();
    void InitWindow();
    void genEnemy();
    void initFonts();
    void initText();
    void renderText();
    void updateText();
    void restart();
public:
    Game();
    ~Game();

    void render();
    void update();
    void pollEvent();

    const bool running() const;
};