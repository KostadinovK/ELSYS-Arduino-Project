#include <Player.h>

Player::Player(Keypad keyPad)
{
    this->keyPad = &keyPad;
    score = 200;
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