#pragma once

#include "Arduino.h"
#include "GameEngine.h"

class MenuItem
{

public:
    String name;
    GameEngine* gameEngine;

	MenuItem(String name, GameEngine* gameEngine);
};