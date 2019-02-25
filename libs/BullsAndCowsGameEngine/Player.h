#pragma once

#include <Number.h>

class Player
{
    public:
        Number guess;
        int score;

        Player();

        void makeGuess();
        void surrender();

        Number getGuess();
        int getScore();
};