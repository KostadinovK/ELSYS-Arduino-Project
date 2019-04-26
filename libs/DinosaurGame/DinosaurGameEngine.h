#pragma once

#include "GameEngine.h"
#include "Arduino.h"

class DinosaurGameEngine : public GameEngine
{
    private:
        const char SELECT_KEY = '*';
        const int jumpLength = 500;

        byte jump;
        int score;
        bool stopScoring;
        unsigned long jumpTime;
        int objectChance;
        byte field[16];
        
        void intro();
        void gameLoop();
        void showHomeScreen();
        void drawHomeGraphics();
        char readKey();
    public:
        DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen);

        void startGame();
};