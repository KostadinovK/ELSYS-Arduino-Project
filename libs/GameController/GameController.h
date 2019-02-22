#pragma once

#include <Arduino.h>

class GameController
{
    private:
        String* options;
        int selectedOption;

    public:
        GameController(String* options, int option);
        void executeSelectedOption();
};