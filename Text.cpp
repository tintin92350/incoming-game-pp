#include "Text.hpp"

using namespace std;

void Tools::Text::centerHorText(sf::Text * _text, const sf::Vector2f _rect, float position_y)
{
	sf::FloatRect bound = _text->getLocalBounds();
	_text->setOrigin(roundf(bound.left + bound.width / 2.0f), roundf(bound.top));
	_text->setPosition(roundf(_rect.x + _rect.y / 2.0f), position_y);
}

void Tools::Text::resetText(sf::Text * _text)
{
	sf::FloatRect bound = _text->getLocalBounds();
	_text->setOrigin(roundf(bound.left), roundf(bound.top));
}