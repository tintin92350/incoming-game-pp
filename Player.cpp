#include "Player.hpp"



Player::Player()
{
}


Player::~Player()
{
}

void Player::create(float posx, float posy, std::string _name)
{
	graphic.setFillColor(sf::Color(255, 60, 60));
	graphic.setPosition(posx, posy);
	graphic.setSize(sf::Vector2f(8.0f, 75.0f));
	this->name = _name;
}
