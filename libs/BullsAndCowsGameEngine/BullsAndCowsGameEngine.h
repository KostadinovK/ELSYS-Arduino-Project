#pragma once

#include <Player.h>
#include <Computer.h>
#include <Arduino.h>

class BullsAndCowsGameEngine
{
    private:
        const int SURRENDER_CODE = 112;
        Player player;
        Computer computer;
        bool gameOver;
        int tries;

        Keypad* keyPad;
        String* triesLog;
    
    public:
        BullsAndCowsGameEngine(Keypad& keyPad);

        void printIntro();
        void startGameLoop();

        int getTries();
        bool getGameState();
};