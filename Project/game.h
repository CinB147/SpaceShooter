#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "asteroid.h"
#include "laser.h"


namespace space {

	/**
	 * \brief Implementation of class Game. UI Initialize and more....
	 */
	class Game
	{
		public:
	
			/**
			 * \brief Default construct with param.
			 * \param window's width
			 * \param window's height
			 */
			Game(const unsigned int width, const unsigned int height);

			
			/**
			 * \brief Check if sf::window is open.
			 * 
			 * \return True 
			 * \return False 
			 */
			bool is_running() const;

			/**
			 * \brief Check if player hp is == 0 or < 0 
			 *
			 * \return True 
			 * \return False 
			 */
			bool gameover();

			/**
			 * \brief .
			 * 
			 */
			void play();

			
			/**
			 * \brief If laser goes out of window's bound, removes laser in vector.pos[i].
			 * Function will check if the laser is out of bound, by taking laster position and window position to compared.
			 * Removes laser from laser vector if statments is true. 
			 * 
			 */
			void laserout();

	
			/**
			 * \brief Event type input that can occured such as close window, mouse/keybord.
			 */
			void event();


			/**
			 * \brief Pushback new Asteroid in vector<Asteroid> container 
			 * Which loops by reset astroidspawn and astroidspawn++ once every 80.
			 */
			void spawnAsteroid();
			
			/**
			 * \brief If laser meets with asteroid, removes asteroid, asteroid takes damage and adds score.
			 * 
			 */
			void asteroidcollision();

			/**
			 * \brief Removes asteroid that player misssed to shoot and flys off window.
			 * 
			 */
			void removeOutAsteroid();


			/**
			 * \brief window.draw everything.
			 * 
			 */
			void draw();

			
			
		private:
			
			int width;
			int height;
			int beamTimer = 20;
			int score = 0;
			int astroidspawn = 0;
			sf::RenderWindow window;
			sf::Texture lasertexture;
			sf::Texture asteroidtexture;
			sf::Font font;
			sf::Text scoreText;
			sf::Text GameOverText;
			sf::Text hpText;
			sf::Text asteroidHPText;
			std::vector<Laser> lasers;
			std::vector<Asteroid> asteroid_vec;
			Player player;
			Laser laser;
			Asteroid asteroid;

			

			
	};


}

#endif // !GAME_H


