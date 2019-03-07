#pragma once

#include <Keypad.h>
#include <Number.h>

class Player
{
    private:
        Keypad* keyPad;
    public:
        Number guess;
        int score;

        Player(Keypad keyPad);

        void makeGuess();
        void surrender();

        Number getGuess();
        int getScore();
};