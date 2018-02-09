#ifndef INCOMING_GAMESTATE_MENU_HPP
#define INCOMING_GAMESTATE_MENU_HPP

// Game state parent
#include "GameState.hpp"

// Define game state
// Menu state
class GSMenu : public GameState
{
    public:

        GSMenu(Game *game);
        ~GSMenu();

        // Initialize the state
        virtual void initialize();
        // Handle events
        virtual void handle_events(const sf::Event &event);
        // Update game content
        virtual void update(const sf::Time &time);
        // Display game content
        virtual void display();

    private:

        // Current button selected
        int mBtnSelected;
        // Select a button
        void _select_button();

        // Game title
        sf::Text mTitle;

        // Play button
        sf::Text mButtons[3];
};

#endif // INCOMING_GAMESTATE_HPP
