#ifndef INCOMING_PLAYER_HPP
#define INCOMING_PLAYER_HPP

// String
#include <string>

// SFML Graphic
#include <SFML\Graphics.hpp>

// Player class
class Player
{
	public:

		Player();
		~Player();

		// Create player
		void create(float posx = 0.0f, float posy = 0.0f, std::string _name = "");

		// Player name
		std::string name;
		// Player graphic to draw
		sf::RectangleShape graphic;
};

#endif // INCOMING_PLAYER_HPP