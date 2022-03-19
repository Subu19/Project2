#include "Headers/Game.h"

void Game::initVeriable(){
    this->window = nullptr;
}

void Game::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 500;
    this->window = new sf::RenderWindow(this->videoMode, "my game", sf::Style::Default);

}

Game::Game(){
    this->initVeriable();
    this->initWindow();

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
            break;
        }
    }
}



void Game::update(){
    this->pollEvents();


}


void Game::render(){

    this->window->clear(sf::Color::Green);

//draw here

    this->window->display();
}


