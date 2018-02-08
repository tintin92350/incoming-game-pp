#include "GSGame.hpp"

#include <iostream>

// Math library
#include <cmath>

#define PI 3.14159265359f

// Game parent (definition)
#include "Game.hpp"

// Game State - Menu
#include "GSMenu.hpp"

using namespace std;

GSGame::GSGame(Game *game)
{
    mGame = game;
}
GSGame::~GSGame()
{

}

// Initialize the state
void GSGame::initialize()
{
    sf::Vector2f world_size(800.0f, 400.0f);
    sf::Vector2f world_position(0.0f, (mGame->getWindowSizeF().y - world_size.y) / 2.0f);

    mWorld_rect = sf::FloatRect(world_position, world_size);

    mWorld_edges[0].setFillColor(sf::Color::White);
    mWorld_edges[0].setSize(sf::Vector2f(world_size.x, 5.0f));
    mWorld_edges[1] = mWorld_edges[0];

    mWorld_edges[0].setPosition(world_position.x, world_position.y - 5.0f);
    mWorld_edges[1].setPosition(world_position.x, world_position.y + world_size.y);

    mWorld_grid.setFillColor(sf::Color(10, 10, 10));
    mWorld_grid.setSize(world_size);
    mWorld_grid.setPosition(world_position);

    mWorld_fieldEdge.setFillColor(sf::Color(50, 50, 50));
    mWorld_fieldEdge.setSize(sf::Vector2f(4.0f, mWorld_rect.height));
    mWorld_fieldEdge.setPosition(world_position.x + world_size.x / 2.0f - 2.0f, world_position.y);

    mPlayer_graphic.setFillColor(sf::Color(255, 60, 60));
    mPlayer_graphic.setPosition(0.0f, world_position.y);
    mPlayer_graphic.setSize(sf::Vector2f(8.0f, 75.0f));

    mAI_graphic = mPlayer_graphic;
    mAI_graphic.setPosition(800.0f - 8.0f, world_position.y);

    mBall_graphic.setFillColor(sf::Color(60, 255, 60));
    mBall_graphic.setRadius(8.0f);
    mBall_graphic.setOrigin(8.0f, 8.0f);
    mBall_graphic.setPosition(world_position + world_size / 2.0f);

    mBall_velocity = 3.0f;
    mBall_angle = 180.0f + 45.0f;
}

// Handle events
void GSGame::handle_events(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
            mGame->change_state(new GSMenu(mGame));
    }
}

// Update game content
void GSGame::update(const sf::Time &time)
{
    mPlayer_graphic.setPosition(0.0f, static_cast<float>(mGame->getMousePosition().y));

    _check_player_position();

    mAI_graphic.setPosition(mAI_graphic.getPosition().x, mPlayer_graphic.getPosition().y);

    float radian_angle = mBall_angle * PI / 180.0f;

    mBall_direction = sf::Vector2f( cosf(radian_angle), sinf(radian_angle) );

    mBall_graphic.move(mBall_direction * mBall_velocity);

    _check_ball_position();
}

// Display game content
void GSGame::display()
{
    mGame->draw(mWorld_grid);
    mGame->draw(mWorld_edges[0]);
    mGame->draw(mWorld_edges[1]);
    mGame->draw(mWorld_fieldEdge);

    mGame->draw(mPlayer_graphic);
    mGame->draw(mAI_graphic);

    mGame->draw(mBall_graphic);
}


void GSGame::_check_player_position()
{
    if(mPlayer_graphic.getPosition().y < mWorld_rect.top)
        mPlayer_graphic.setPosition(0.0f, mWorld_rect.top);
    else if(mPlayer_graphic.getPosition().y + mPlayer_graphic.getSize().y > mWorld_rect.top + mWorld_rect.height)
        mPlayer_graphic.setPosition(0.0f, mWorld_rect.top + mWorld_rect.height - mPlayer_graphic.getSize().y);
}

void GSGame::_check_ball_position()
{
    if(mBall_graphic.getPosition().y - 8.0f < mWorld_rect.top)
    {
        mBall_graphic.setPosition(mBall_graphic.getPosition().x, mWorld_rect.top + 8.0f);
        mBall_angle = -mBall_angle;
    }
    else if(mBall_graphic.getPosition().y + 8.0f > mWorld_rect.top + mWorld_rect.height)
    {
        mBall_graphic.setPosition(mBall_graphic.getPosition().x, mWorld_rect.top + mWorld_rect.height - 8.0f);
        mBall_angle = -mBall_angle;
    }

    if( mBall_graphic.getPosition().y >= mPlayer_graphic.getPosition().y &&
        mBall_graphic.getPosition().y <= mPlayer_graphic.getPosition().y + mPlayer_graphic.getSize().y)
    {
        if(mBall_graphic.getPosition().x - 8.0f < mPlayer_graphic.getPosition().x + mPlayer_graphic.getSize().x)
            _divert_ball_players(0);
    }

    if(mBall_graphic.getPosition().y >= mAI_graphic.getPosition().y &&
            mBall_graphic.getPosition().y <= mAI_graphic.getPosition().y + mAI_graphic.getSize().y)
    {
        if(mBall_graphic.getPosition().x + 8.0f > mAI_graphic.getPosition().x)
            _divert_ball_players(1);
    }
}

void GSGame::_divert_ball_players(uint id)
{
    float sidesize = mPlayer_graphic.getSize().y / 2.0f;
    float max_angle = 15.0f;
    float difference = 0.0f;
    float coef = 1.0f;

    float player_posy = 0.0f;

    if(id == 0) player_posy = mPlayer_graphic.getPosition().y;
    else if(id == 1) player_posy = mAI_graphic.getPosition().y;

    if(mBall_graphic.getPosition().y <= player_posy + sidesize)
        difference = abs(player_posy - mBall_graphic.getPosition().y);
    else
        difference = abs(player_posy + sidesize - mBall_graphic.getPosition().y);
    coef = difference / sidesize;

    mBall_angle = 180.0f + (coef * max_angle) - mBall_angle;

    if(id == 0)
        mBall_graphic.setPosition(mPlayer_graphic.getPosition().x + mPlayer_graphic.getSize().x + 8.0f, mBall_graphic.getPosition().y);
    else if(id == 1)
        mBall_graphic.setPosition(mAI_graphic.getPosition().x - 8.0f, mBall_graphic.getPosition().y);
}
