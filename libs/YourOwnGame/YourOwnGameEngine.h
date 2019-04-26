#pragma once

#include <Arduino.h>
#include<LiquidCrystal.h>
#include "GameEngine.h"

class YourOwnGameEngine : public GameEngine
{
    public:
        YourOwnGameEngine(Keypad& keyPad, LiquidCrystal& screen) : GameEngine(keyPad, screen){}

        void startGame()
        {
            screen->clear();
            screen->print("Write your own");
            screen->setCursor(0,1);
            screen->print("game here");
        }
};