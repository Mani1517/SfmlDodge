#include "headers/Game.h"

#define WIDTH 360
#define HEIGHT 640

Game::Game()
{
    this->InitVariable();
    this->InitWindow();
    this->initFonts();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}

void Game::InitWindow()
{
    this->videoMode = sf::VideoMode(WIDTH,HEIGHT);
    this->window = new sf::RenderWindow(this->videoMode, "Dodge", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::InitVariable()
{
    this->endGame = false;
    this->player = Player((float)(WIDTH/2 - 25), (float)(HEIGHT - 50));
    this->enemy = Enemy(0.f, 0.f);
    this->score = 0;
    this->dead = false;
}

void Game::initFonts()
{
    if(!font.loadFromFile("Assets/PixelSquare.ttf"))
        std::cout<<"Error Fonts!!"<<std::endl;
}

void Game::initText()
{
    this->guiText.setFont(font);
    this->guiText.setFillColor(sf::Color::Black);
    this->guiText.setCharacterSize(25);
    this->guiText.setPosition(10.f, 5.f);

    this->healthText.setFont(font);
    this->healthText.setFillColor(sf::Color::Black);
    this->healthText.setCharacterSize(20);
    this->healthText.setPosition(10.f, 30.f);
}

void Game::renderText()
{
    this->window->draw(this->guiText);
    this->window->draw(this->healthText);
}

void Game::updateText()
{
    std::stringstream scoreText;
    scoreText << "Score: " << this->score;

    std::stringstream health;
    health << "Health: "<<this->player.health;

    this->guiText.setString(scoreText.str());
    this->healthText.setString(health.str());
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while(this->window->pollEvent(this->event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
            if(this->event.key.code == sf::Keyboard::R&&dead)
            {
                this->restart();
            }
            break;
        }
    }
}

void Game::update()
{
    this->pollEvent();
    this->player.update(this->window);
    this->updateText();
    if(this->clock.getElapsedTime().asSeconds() - delay >= 0.3f && !dead)
    {
        this->score += 1;
        this->genEnemy();
    }

    for(this->iter = this->enemyLst.begin(); this->iter != this->enemyLst.end(); iter++){
        iter->update();
        if(iter->destroyWindow()){
            iter = enemyLst.erase(iter);
        }
        else if(iter->getShape().getGlobalBounds().intersects(this->player.getShape().getGlobalBounds())){
            iter = enemyLst.erase(iter);
            this->player.health--;
        } else if(this->player.health <= 0){
            iter = enemyLst.erase(iter);
            this->dead = true;
        }
    }
}

void Game::render()
{
    this->window->clear(sf::Color(250,250,230,255));
    
    this->player.render(this->window);
    this->renderText();

    for(this->iter = this->enemyLst.begin(); this->iter != this->enemyLst.end(); iter++){
        iter->render(this->window);
    }

    this->window->display();
}

void Game::genEnemy()
{
    randNum = rand() % 310;
    this->enemy = Enemy(randNum,0.f);
    this->enemyLst.push_back(enemy);
    this->delay = clock.getElapsedTime().asSeconds();
}

void Game::restart()
{
    this->score = 0;
    this->player.health = 3;
    this->dead = false;
}