#ifndef INCOMING_GAME_HPP
#define INCOMING_GAME_HPP

// Render window and events
#include <SFML/Graphics.hpp>
// SFML network
#include <SFML/Network.hpp>

// Assets Manager
#include "AssetManager.hpp"

// Game state
#include "GameState.hpp"

// Game class
class Game
{
    public:

        // Game construct
        Game();

        // Initialize base game
        bool initialize();
        // Game main loop
        void run();
        // Close function
        void close();

        // Get mouse position
        sf::Vector2i getMousePosition() const;
        // Get window size
        sf::Vector2u getWindowSize() const;
        // Get window size in float
        sf::Vector2f getWindowSizeF() const;
        // Draw function
        void draw(const sf::Drawable &obj);

        // Asset Manager
        AssetManager asset_manager;

        // Push a new state and initialize it
        void push_state(GameState* _n_state);
        // Pop the last state and free memory
        void pop_state();
        // Change state
        void change_state(GameState* _n_state);
        // Get last state
        GameState* get_last_state();

    private:

        // Game clock
        sf::Clock mGameClock;

        // Handle events
        void _handle_events();
        // Update game content
        void _update(const sf::Time &time);
        // Display game content
        void _display();

        // States
        std::vector<GameState*> mStates;

        // Window
        sf::RenderWindow mWindow;
        // Game running
        bool mRunning;
};

#endif
