#ifndef INCOMING_GAMESTATE_HPP
#define INCOMING_GAMESTATE_HPP

// SFML Graphics
#include <SFML/Graphics.hpp>

// Game class (definition needed)
class Game;

// Define game state base class
class GameState
{
    public:

        GameState() { }
        ~GameState() { }

        // Initialize the state
        virtual void initialize() = 0;
        // Handle events
        virtual void handle_events(const sf::Event &event) = 0;
        // Update game content
        virtual void update(const sf::Time &time) = 0;
        // Display game content
        virtual void display() = 0;

    protected:

        // Game engine parent
        Game* mGame;
};

#endif // INCOMING_GAMESTATE_HPP
