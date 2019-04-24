#pragma once

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>

#include "BullsAndCowsGameEngine.h"

class GameController
{
    private:
        String* options;
        int selectedOption;
        Keypad* keyPad;
        LiquidCrystal* screen;

    public:
        GameController(Keypad& keyPad, LiquidCrystal& screen, String* options, int option);
        void executeSelectedOption();
};