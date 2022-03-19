#include "Game.h"

void Game::initVeriable(){
    this->window = nullptr;
}

void Game::initWindow(){
    this->videoMode.height = this->videoMode.getDesktopMode().height;
    this->videoMode.width =  this->videoMode.getDesktopMode().width;
    
    this->window = new sf::RenderWindow(this->videoMode, "my game", sf::Style::Default);
    this->window->setFramerateLimit(100);

}
void Game::initEnemy(){
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
    this->enemy.setFillColor(sf::Color::Green);

}
Game::Game(){
    this->initVeriable();
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
        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape){
                this->window->close();
            }
            if(this->ev.key.code == sf::Keyboard::D){
                this->enemy.setPosition(this->enemy.getPosition().x + 10.f,this->enemy.getPosition().y);
            }
            if(this->ev.key.code == sf::Keyboard::A){
                this->enemy.setPosition(this->enemy.getPosition().x - 10.f,this->enemy.getPosition().y);
            }
             if(this->ev.key.code == sf::Keyboard::W){
                this->enemy.setPosition(this->enemy.getPosition().x,this->enemy.getPosition().y - 10.f);
            }
             if(this->ev.key.code == sf::Keyboard::S){
                this->enemy.setPosition(this->enemy.getPosition().x ,this->enemy.getPosition().y + 10.f);
            }
            break;
        }
    }
}



void Game::update(){
    this->pollEvents();


}


void Game::render(){

    this->window->clear(sf::Color::Black);

//draw here
this->window->draw(this->enemy);

    this->window->display();
}


