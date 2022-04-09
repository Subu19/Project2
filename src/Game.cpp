#include <iostream>
#include <sstream>
#include "Game.h"
using namespace std;
void Game::initVeriable(){
    this->window = nullptr;


    this->points =0;
    this->enemySpawnTimerMax = 100.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;
    this->health = 10;
    this->endGame = false;

}
void Game::initFont(){
    this->font.loadFromFile("Fonts/Organic-Relief.ttf");
   
}
void Game::initText(){
    this->uiText.setFont(this->font);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setCharacterSize(24);
    this->uiText.setString("NONE");
    this->uiText.setPosition(10.f,10.f);
}
void Game::initWindow(){
    this->videoMode.height = this->videoMode.getDesktopMode().height;
    this->videoMode.width =  this->videoMode.getDesktopMode().width;
    
    this->window = new sf::RenderWindow(this->videoMode, "my game", sf::Style::Default);
    this->window->setFramerateLimit(100);

}
void Game::initEnemy(){
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Green);

}
Game::Game(){
    this->initVeriable();
    this->initFont();
    this->initText();
    this->initWindow();
    this->initEnemy();

}
Game::~Game(){
    delete this->window;

}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        }
    }
}

void Game::updateMousePos(){
    this->mousePos = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::update(){
    this->pollEvents();
    if(this->endGame == false){
    this->updateMousePos();
    this->updateEnemies();
    this->updateText();
    }
    if(this->health < 0)
    this->endGame = true;

}
void Game::updateText(){
    std::stringstream ss;
    ss <<"HEALTH: " << this->health;
    this->uiText.setString(ss.str());
    // this->uiText.setString();
}

void Game::renderText(){
    this->window->draw(this->uiText);
}

void Game::spawnEnemy(){
    //spawn new enemy
    this->enemy.setPosition(static_cast<float>( rand()% static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f);
    this->enemy.setFillColor(sf::Color::Blue);
    this->enemies.push_back(this->enemy);

}
void Game::updateEnemies(){
    if(this->enemies.size()< this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer +=1.f;    

    }
    //move enemy
    for (int i = 0; i < this->enemies.size(); i++)
    {
        /* code */
        this->enemies[i].move(0.f, 5.f);
        //check if the enemy passed the border
        if(this->enemies[i].getPosition().y >= this->window->getSize().y){
                 this->enemies.erase(this->enemies.begin()+ i);
                 health -= 1;
        }
    }
    //click event

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(mouseHeld == false){
            mouseHeld= true;
            for (int i = 0; i < this->enemies.size(); i++)
            {
                /* code */
                if(this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
                    this->enemies.erase(this->enemies.begin()+ i);
                }
            }
            
        }
        
    }else{
        this->mouseHeld = false;
    }
    
    
}
void Game::renderEnemies(){
    for (auto  &e: this->enemies)
    {
        /* code */
    this->window->draw(e);
    }
    
}


void Game::render(){

    this->window->clear(sf::Color::Black);

//draw here
// this->window->draw(this->enemy);
    this->renderEnemies();
    this->renderText();
    this->window->display();
}


