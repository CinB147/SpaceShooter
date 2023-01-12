#include "laser.h"


space::Laser::Laser(sf::Texture* texture, sf::Vector2f pos) {
	this->shape.setTexture(*texture);
	this->shape.setScale(0.2f, 0.2f);
	this->shape.setPosition(pos);
}




space::Laser::~Laser() {

}
