#include "GSMenu.hpp"

// Math library
#include <cmath>

// Game parent (definition)
#include "Game.hpp"

// Tools - Text
#include "Text.hpp"

// Game State - Game
#include "GSGame.hpp"

#define cht(object, rect, pos) Tools::Text::centerHorText(object, rect, pos);

GSMenu::GSMenu(Game *game) : mBtnSelected(0)
{
    mGame = game;
}
GSMenu::~GSMenu()
{

}

// Initialize the state
void GSMenu::initialize()
{
    mTitle = sf::Text("-- INCOMING --", *mGame->asset_manager.get_font(0), 50);
    cht(&mTitle, sf::Vector2f(0.0f, mGame->getWindowSizeF().x), 80.0f);

    mButtons[0] = sf::Text("Play", *mGame->asset_manager.get_font(0), 35);

    mButtons[1] = sf::Text("Settings", *mGame->asset_manager.get_font(0), 20);
    mButtons[1].setFillColor(sf::Color(60, 60, 60));

    mButtons[2] = sf::Text("Exit", *mGame->asset_manager.get_font(0), 20);
}

// Handle events
void GSMenu::handle_events(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Up)
        {
            //mBtnSelected = mBtnSelected - 1 < 0 ? 2 : mBtnSelected - 1;
            mBtnSelected = mBtnSelected == 0 ? 2 : 0;
            _select_button();
        }
        else if(event.key.code == sf::Keyboard::Down)
        {
            //mBtnSelected = mBtnSelected + 1 > 2 ? 0 : mBtnSelected + 1;
            mBtnSelected = mBtnSelected == 2 ? 0 : 2;
            _select_button();
        }
        else if(event.key.code == sf::Keyboard::Return)
        {
            if(mBtnSelected == 0)
                mGame->change_state(new GSGame(mGame));
            else if(mBtnSelected == 2)
                mGame->close();
        }
    }
}

// Update game content
void GSMenu::update(const sf::Time &time)
{
    cht(&mButtons[0], sf::Vector2f(0.0f, mGame->getWindowSizeF().x), 200.0f);
    cht(&mButtons[1], sf::Vector2f(0.0f, mGame->getWindowSizeF().x), 300.0f);
    cht(&mButtons[2], sf::Vector2f(0.0f, mGame->getWindowSizeF().x), 400.0f);
}

// Display game content
void GSMenu::display()
{
    mGame->draw(mTitle);

    for (size_t i = 0; i < 3; i++)
        mGame->draw(mButtons[i]);
}


// Select a button
void GSMenu::_select_button()
{
    for (size_t i = 0; i < 3; i++) {
        if(mBtnSelected == i)
            mButtons[i].setCharacterSize(35);
        else
            mButtons[i].setCharacterSize(20);
    }
}
