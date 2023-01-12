#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include "laser.h"

namespace space {
	/**
	 * \brief Implementation of player class. Player controls and initialize MAXHp and Hp, setting textured of spaceship. 
	 */
	class Player {
	private:
		int MAXHP;
		sf::RenderWindow &window;
		sf::Texture texture;
	
	public:
		int HP;

		/**
		 * \brief Construct with param.
		 * 
		 * \param 2D drawable window
		 */
		Player(sf::RenderWindow& window);
		sf::Sprite shape;
		Player() = default;

		/**
		 * \brief Iinput controller with keybord. Where control on spaceship.
		 * 
		 */
		void update();


		/**
		 * \brief Collision with window to prevent player goes out of window.
		 * 
		 */
		void playercollision();

		/**
		 * \brief player MAXHP.
		 * 
		 * \return player MAXHP
		 */
		int getMaxHP();

		/**
		 * \brief player HP.
		 * 
		 * \return player HP
		 */
		int getHP();


		/**
		 * \brief Player's Sprite position .
		 * 
		 * \return Position in 2D vector
		 */
		sf::Vector2f getplayerpos();

		~Player();

	};
}

#endif // !PLAYER_H
