#pragma once
#ifndef LASER_H
#define LASER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include "player.h"

namespace space {
	/**
	 * \brief Implementation of laser class. Settinf texture position of laser in paralle with spaceship
	 */
	class Laser {
	public:
		sf::Sprite shape;
		sf::Texture texture;

		Laser() = default;


		/**
		 * \brief Contruct with param.
		 * 
		 * \param Image object texture
		 * \param position of x and y from 2Dvector
		 */
		Laser(sf::Texture* texture, sf::Vector2f pos);

		~Laser();

	private:

	};

}

#endif // !LASER_H



