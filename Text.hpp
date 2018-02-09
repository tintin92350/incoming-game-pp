#ifndef INCOMING_TOOL_TEXT_HPP
#define INCOMING_TOOL_TEXT_HPP

// SFML Graphics
#include <SFML/Graphics.hpp>

// Math library
#include <cmath>

namespace Tools
{
    namespace Text
    {
		void centerHorText(sf::Text* _text, const sf::Vector2f _rect, float position_y);
		void resetText(sf::Text* _text);
    }
}

#endif // INCOMING_TOOL_TEXT_HPP
