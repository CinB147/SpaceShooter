#include "asteroid.h"


space::Asteroid::Asteroid(sf::Texture* texture, sf::Vector2u windowsize) {
    srand(time(NULL));
    this->HPMax = getHPMAX();
    this->HP = this->HPMax;
    this->shape.setTexture(*texture);
    this->shape.setScale(getsize(), getsize());
    this->shape.setPosition(windowsize.x , rand() % windowsize.y - this->shape.getGlobalBounds().height);
}

int space::Asteroid::getHPMAX()
{
    return HPMax = (rand() % 5 + 1) * 10;
}

float space::Asteroid::getsize()
{
    if (HPMax == 10) {
        return 0.08f;
    }
    else if (HPMax == 20) {
        return 0.1f;
    }
    else if (HPMax == 30) {
        return 0.13f;
    }
    else if (HPMax == 40) {
        return 0.15f;
    }
    else if (HPMax == 50) {
        return 0.17f;
    }
}

space::Asteroid::~Asteroid() {}
