#include "player.h"


space::Player::Player(sf::RenderWindow& window) 
    :MAXHP(100), HP(MAXHP),  window(window) 
{
    this->texture.loadFromFile("spaceship.png");
	this->shape.setTexture(texture);

	this->shape.setScale(0.2f, 0.2f);
	this->shape.setPosition(10.f, 350.f);


}

void space::Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0.f, -10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-10.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0.f, 10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(10.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        shape.move(0.f, -10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape.move(-10.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        shape.move(0.f, 10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape.move(10.f, 0.f);
    }
   
   
}

void space::Player::playercollision()
{
    
    if (shape.getPosition().x <= 0) { //left
        shape.setPosition(0.f, shape.getPosition().y);
    }
    if (shape.getPosition().x >= window.getSize().x - shape.getGlobalBounds().width) { //right
        shape.setPosition(window.getSize().x - shape.getGlobalBounds().width, shape.getPosition().y);
    }
    if (shape.getPosition().y >= window.getSize().y - shape.getGlobalBounds().height) { //bottom
        shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getGlobalBounds().height);
    }
    if (shape.getPosition().y <= 0) { //top
        shape.setPosition(shape.getPosition().x, 0.f);
    }
}

int space::Player::getMaxHP()
{
    return MAXHP;
}

int space::Player::getHP()
{
    return HP;
}

sf::Vector2f space::Player::getplayerpos()
{
    return shape.getPosition();
}

space::Player::~Player() {

}