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
        void centerHorText(sf::Text* _text, const sf::Vector2f _rect, float position_y)
        {
            sf::FloatRect bound = _text->getLocalBounds();
            _text->setOrigin(roundf(bound.left + bound.width / 2.0f), roundf(bound.top));
            _text->setPosition(roundf(_rect.x + _rect.y / 2.0f), position_y);
        }
    }
}

#endif // INCOMING_TOOL_TEXT_HPP
