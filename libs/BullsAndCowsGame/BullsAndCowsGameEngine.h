#pragma once

#include <Player.h>
#include <Computer.h>

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>
#include "GameEngine.h"

class BullsAndCowsGameEngine : public GameEngine
{
    private:
        Player player;
        Computer computer;
        bool gameOver;
        int tries;

        String triesLog;

        void drawIntro();
        void startGameLoop();
        void checkForBullsAndCows();
        void printLog();
        int makeGuess();
        bool hasDuplicates(int value[]);

    
    public:
        BullsAndCowsGameEngine(Keypad& keyPad, LiquidCrystal& screen);

        void startGame();

        int getTries();
        bool getGameState();
};