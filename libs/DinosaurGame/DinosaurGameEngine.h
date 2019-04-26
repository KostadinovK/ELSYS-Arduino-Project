#pragma once

#include "GameEngine.h"

class DinosaurGameEngine : public GameEngine
{
    private:
        const char RIGHT_KEY = '6';
        const char UP_KEY = '2';
        const char DOWN_KEY = '8';
        const char LEFT_KEY = '4';
        const char SELECT_KEY = '*';

        void showHomeScreen();
        void drawHomeGraphics();
        void drawBarrier();
        char readKey();
        void showCrashScreen();
        void updateLcd();
        void printScore();

    public:
        DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen);

        void startGame();
};