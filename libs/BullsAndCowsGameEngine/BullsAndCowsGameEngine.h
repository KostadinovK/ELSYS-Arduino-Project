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

        String* triesLog;
    
    public:
        BullsAndCowsGameEngine();

        void printIntro();
        void startGameLoop();

        int getTries();
        bool getGameState();
};