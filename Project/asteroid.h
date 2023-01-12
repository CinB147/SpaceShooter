#pragma once

#include <SFML/Graphics.hpp>

namespace space {

	/**
	 * \brief Implementation of asteroid class. Initialize asteroid HP/MAXHP and set asteroid texture. 
	 */
	class Asteroid {
	public:
		int HP;
		int HPMax;
		sf::Sprite shape;
		sf::Texture texture;


		/**
		 * \brief contruct with param.
		 * 
		 * \param Image object texture
		 * \param windowsize x and y
		 */
		Asteroid(sf::Texture* texture, sf::Vector2u windowsize);

		
		/**
		 * \brief Random MAXHP for asteroid. Get Asteroid's MAXHp.
		 * 
		 * \return asteroid's MAXHP
		 */
		int getHPMAX();

		
		/**
		 * \brief Take Asteroid MAXHp as statments, Depends on MAXHp that gets random. Which can be use to set Sprite scale .
		 * 
		 * \return Size of Asteroid
		 */
		float getsize();

		~Asteroid();

	};
}