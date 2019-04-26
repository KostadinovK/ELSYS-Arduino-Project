#pragma once

#include "GameEngine.h"

class DinosaurGameEngine : public GameEngine
{
    public:
        DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen);

        void startGame();
};