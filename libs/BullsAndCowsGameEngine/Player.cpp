#include <Player.h>

Player::Player()
{
    score = 0;
    guess = Number();
}

void Player::makeGuess()
{

}

void Player::surrender()
{
    
}

Number Player::getGuess()
{
    return this->guess;
}

int Player::getScore()
{
    return this->score;
}