#pragma once

#include <Player.h>
#include <Computer.h>

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>

class BullsAndCowsGameEngine
{
    private:
        const int SURRENDER_CODE = 112;
        Player player;
        Computer computer;
        bool gameOver;
        int tries;

        Keypad* keyPad;
        LiquidCrystal* screen;
        String triesLog;
    
    public:
        BullsAndCowsGameEngine(Keypad keyPad, LiquidCrystal screen);

        void drawIntro();
        void startGameLoop();

        int getTries();
        bool getGameState();
};