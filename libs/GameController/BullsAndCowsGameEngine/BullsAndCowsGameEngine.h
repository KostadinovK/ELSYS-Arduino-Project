#pragma once

#include <Player.h>
#include <Computer.h>

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>

class BullsAndCowsGameEngine
{
    private:
        Player player;
        Computer computer;
        bool gameOver;
        int tries;

        Keypad* keyPad;
        LiquidCrystal* screen;
        String triesLog;

        void drawIntro();
        void startGameLoop();
        void checkForBullsAndCows(Number& number);
        void printLog();
        void askForRestart(bool& gameOver);
        int makeGuess();
        bool hasDuplicates(int value[]);

    
    public:
        BullsAndCowsGameEngine(Keypad& keyPad, LiquidCrystal& screen);

        void startGame();

        int getTries();
        bool getGameState();
};