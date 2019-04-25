#pragma once

#include <Arduino.h>
#include <Keypad.h>
#include<LiquidCrystal.h>

#include "BullsAndCowsGameEngine.h"
#include "MenuItem.h"

class GameController
{
    private:
        MenuItem* options;
        int selectedOption;
        Keypad* keyPad;
        LiquidCrystal* screen;

    public:
        GameController(Keypad& keyPad, LiquidCrystal& screen, MenuItem* options, int option);
        void executeSelectedOption();
};