#include "game.h"
#include "player.h"
#include "asteroid.h"
#include "laser.h"


space::Game::Game(const unsigned int width, const unsigned int height)
    : width(width), height(height), window(sf::VideoMode(width, height), "Spaceship in Space"), player(window), laser(&lasertexture,player.shape.getPosition()) , asteroid(&asteroidtexture,window.getSize())
{
    window.setFramerateLimit(60);    
    
    //Init laser 
    lasertexture.loadFromFile("laser.png");

    //Init asteroid
    asteroidtexture.loadFromFile("asteroid.png");
    
    //Init Font
    font.loadFromFile("Fonts/Fluff.ttf");

    //UI init
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(1700.f, 10.f);
   
    GameOverText.setFont(font);
    GameOverText.setCharacterSize(120);
    GameOverText.setFillColor(sf::Color::Red);
    GameOverText.setPosition(700.f, window.getSize().y / 2);
    GameOverText.setString("GAME OVER");

    hpText.setFont(font);
    hpText.setCharacterSize(18);
    hpText.setFillColor(sf::Color::White);


    asteroidHPText.setFont(font);
    asteroidHPText.setCharacterSize(18);
    asteroidHPText.setFillColor(sf::Color::White);
}


bool space::Game::is_running() const {
	return window.isOpen();
}

bool space::Game::gameover()
{
    if (player.getHP() == 0) {
        return true;
    }
    else if (player.getHP() > 0) {
        return false;
    }
}


void space::Game::play() {
    
    asteroid_vec.push_back(Asteroid(&asteroidtexture,window.getSize()));
    sf::Clock clock;

    // run the program as long as the window is open
    while (is_running())
    {
        event();

        if (!gameover()) {
            
            
            player.update(); //player plays

            hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
            hpText.setString(std::to_string(player.getHP()) + "/" + std::to_string(player.getMaxHP()));

            player.playercollision(); // collision with window to provent player goes out of window

            //laser prevent laser being pushback without 'gaping'
            if (beamTimer < 20) {
                beamTimer++;
            }

            //HP goes up every 2sec
            if (clock.getElapsedTime().asSeconds() > 2) {
                player.HP += 1;
                clock.restart();
                if (player.HP > player.getMaxHP()) { //prevent HP goes above MAXHP
                    player.HP = player.getMaxHP();
                }
            }
            
            
            //laser goes out of window bounds
            for (size_t i = 0; i < lasers.size(); i++) {
                lasers[i].shape.move(20.f, 0.f); //laster moves towards right side

            }
            asteroidcollision();
            laserout();

            //asteroid goes out of window bounds , intersect with players
            for (size_t i = 0; i < asteroid_vec.size(); i++) {
                asteroid_vec[i].shape.move(-2.0f, 0.f);
                if (asteroid_vec[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
                    score -= 10;
                    asteroid_vec.erase(asteroid_vec.begin() + i);
                    player.HP -= 10; //players take damage
                    break;
                }
            }

            removeOutAsteroid();
            spawnAsteroid();
            
        }

        scoreText.setString("Score : " + std::to_string(score));


        // clear the window with black color
        window.clear(sf::Color::Black);

        draw();

        // end the current frame
        window.display();
    }
}




void space::Game::laserout()
{
    for (size_t i = 0; i < lasers.size(); i++) {
        if (lasers[i].shape.getPosition().x > window.getSize().x) { //out of window bounds
            lasers.erase(lasers.begin() + i);
            break;
        }
    }

}


void space::Game::event()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) { 
            window.close(); 
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && beamTimer >= 20) { //for keyboard
            lasers.push_back(Laser(&lasertexture, player.shape.getPosition()));
            beamTimer = 0; //reset timer
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && beamTimer >= 20) { //for spacebar
            lasers.push_back(Laser(&lasertexture, player.shape.getPosition()));
            beamTimer = 0; //reset timer
        }
    }

}


void space::Game::spawnAsteroid()
{
    if (astroidspawn < 80) {
        astroidspawn++;
    }
    else if (astroidspawn >= 80) {
        asteroid_vec.push_back(Asteroid(&asteroidtexture, window.getSize()));
        astroidspawn = 0;
    }
}



void space::Game::asteroidcollision()
{
    for (size_t i = 0; i < lasers.size(); i++) {
        for (size_t j = 0; j < asteroid_vec.size(); j++) {
            if (lasers[i].shape.getGlobalBounds().intersects(asteroid_vec[j].shape.getGlobalBounds())) { 

                if (asteroid_vec[j].HP <= 10) {
                    score += asteroid_vec[j].HPMax;
                    asteroid_vec.erase(asteroid_vec.begin() + j);
                }
                else {
                    asteroid_vec[j].HP -= 10;
                }
                lasers.erase(lasers.begin() + i);
                break;
            }
        }
    }
}

void space::Game::removeOutAsteroid()
{
    for (size_t i = 0; i < asteroid_vec.size(); i++) {
        if (asteroid_vec[i].shape.getPosition().x <= 0 - asteroid_vec[i].shape.getGlobalBounds().width) {

            asteroid_vec.erase(asteroid_vec.begin() + i);
            break;

        }
    }
}

void space::Game::draw()
{
    // draw everything here...

    //Player
    window.draw(player.shape);

    //score
    window.draw(scoreText);

    //HP
    window.draw(hpText);

    //Gameover
    if (gameover()) {
        window.draw(GameOverText);
    }

    ////laser
    for (size_t i = 0; i < lasers.size(); i++) {
        window.draw(lasers[i].shape);
    }

    for (size_t i = 0; i < lasers.size(); i++) {
        window.draw(lasers[i].shape);
    }

    //asteroid
    for (size_t i = 0; i < asteroid_vec.size(); i++) {
        asteroidHPText.setString(std::to_string(asteroid_vec[i].HP) + "/" + std::to_string(asteroid_vec[i].HPMax));
        asteroidHPText.setPosition(asteroid_vec[i].shape.getPosition().x, asteroid_vec[i].shape.getPosition().y - asteroidHPText.getGlobalBounds().height);
        window.draw(asteroidHPText);
        window.draw(asteroid_vec[i].shape);
    }
}



