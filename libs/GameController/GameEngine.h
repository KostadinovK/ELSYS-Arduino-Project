#pragma once

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>

class GameEngine
{
    protected:
        Keypad* keyPad;
        LiquidCrystal* screen;
    public:
	    GameEngine(Keypad& keyPad, LiquidCrystal& screen);

        virtual void startGame() = 0;
};