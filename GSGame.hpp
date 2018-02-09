#ifndef INCOMING_GAMESTATE_GAME_HPP
#define INCOMING_GAMESTATE_GAME_HPP

// Game state parent
#include "GameState.hpp"

// Player
#include "Player.hpp"

// Define game state
// Game state
class GSGame : public GameState
{
    public:

        GSGame(Game *game);
        ~GSGame();

        // Initialize the state
        virtual void initialize();
        // Handle events
        virtual void handle_events(const sf::Event &event);
        // Update game content
        virtual void update(const sf::Time &time);
        // Display game content
        virtual void display();

    private:

        sf::FloatRect       mWorld_rect;
        sf::RectangleShape  mWorld_edges[2];
        sf::RectangleShape  mWorld_grid;
        sf::RectangleShape  mWorld_fieldEdge;

		Player				mPlayer;
		Player				mAI;

		sf::Text			mPlayersName[2];

        sf::CircleShape     mBall_graphic;
        sf::Vector2f        mBall_direction;
        float               mBall_velocity;
        float               mBall_angle;

        void _check_player_position();
        void _check_ball_position();
        void _divert_ball_players(unsigned int id);

};

#endif // INCOMING_GAMESTATE_GAME_HPP
