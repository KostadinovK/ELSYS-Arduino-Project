#pragma once

#include <Arduino.h>
#include "BullsAndCowsGameEngine.h"

class GameController
{
    private:
        String* options;
        int selectedOption;

    public:
        GameController(String* options, int option);
        void executeSelectedOption();
};