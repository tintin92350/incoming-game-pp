#include "Game.hpp"

// Input / Output
#include <iostream>

// Math
#include <cmath>

// Game state - Menu
#include "GSMenu.hpp"

using namespace std;

// Game construct
Game::Game() : mRunning(true)
{
    // Initialize Fonts
    if(!asset_manager.load_font(0, "Fonts/dina10px.ttf"))
        std::cerr << "/* ATTENTION : Could not open the font */" << '\n';
}


// Initialize base game
bool Game::initialize()
{
    // Context Settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the window
    mWindow.create(sf::VideoMode(800, 600), "INCOMING", sf::Style::Default, settings);
    mWindow.setFramerateLimit(60);
    mWindow.setPosition(sf::Vector2i(960 - getWindowSize().x / 2, 540 - getWindowSize().y / 2));

    // Create the first state (menu)
    push_state(new GSMenu(this));

    // Clock restart
    mGameClock.restart();

    // All is ok
    return true;
}


// Game main loop
void Game::run()
{
    // While the game still running
    // We continue and repeate the main game loop
    while (mRunning) {

        sf::Time elapsed = mGameClock.restart();

        this->_handle_events();
        this->_update(elapsed);
        this->_display();

        mGameClock.restart();
    }

    // Clear states
    while (!mStates.empty()) {
        pop_state();
    }

    // Clear resources
    asset_manager.clear();
}

// Close function
void Game::close()
{
    // Set running to false
    mRunning = false;

    // Close the window
    mWindow.close();
}


// Get window size
sf::Vector2u Game::getWindowSize() const
{
    return mWindow.getSize();
}
// Get window size in float
sf::Vector2f Game::getWindowSizeF() const
{
    return sf::Vector2f(getWindowSize());
}
// Get mouse position
sf::Vector2i Game::getMousePosition() const
{
    return sf::Mouse::getPosition(mWindow);
}
// Draw function
void Game::draw(const sf::Drawable &obj)
{
    mWindow.draw(obj);
}

// Push a new state and initialize it
void Game::push_state(GameState* _n_state)
{
    // Initialize the state
    _n_state->initialize();

    // Push it to the state stack
    mStates.push_back(_n_state);
}
// Pop the last state and free memory
void Game::pop_state()
{
    if(!mStates.empty())
    {
        delete mStates.back();
        mStates.pop_back();
    }
}
// Change state
void Game::change_state(GameState* _n_state)
{
    pop_state();
    push_state(_n_state);
}
// Get last state
GameState* Game::get_last_state()
{
    return mStates.back();
}

// Handle events
void Game::_handle_events()
{
    // Event handler
    sf::Event gevent;

    // While any event is catched
    // by the window, we keep handle them
    while(mWindow.pollEvent(gevent))
    {
        // Close event (global)
        if(gevent.type == sf::Event::Closed)
            this->close();

        // Handle user events on the current state
        // Only if the state exist
        if(!mStates.empty())
            get_last_state()->handle_events(gevent);
    }
}


// Update game content
void Game::_update(const sf::Time &time)
{
    // Update the current state
    // Only if the state exist
    if(!mStates.empty())
        get_last_state()->update(time);
}


// Display game content
void Game::_display()
{
    // Clear window / screen
    mWindow.clear();

    // Draw the current state
    // Only if the state exist
    if(!mStates.empty())
        get_last_state()->display();

    // Display window content
    mWindow.display();
}
