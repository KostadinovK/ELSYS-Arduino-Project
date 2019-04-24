#pragma once

#include "Arduino.h"
#include <Keypad.h>
#include<LiquidCrystal.h>

class Menu
{
private:
	const char SELECT_KEY = '*';
	const char DOWN_KEY = '8';
	const char UP_KEY = '2';

	String* options;
	int optionsCount;
	int optionIndex;

	LiquidCrystal* screen;
	Keypad* keyPad;

	void run();

public:
	Menu(String* options, int optionsCount, LiquidCrystal& screen, Keypad& keyPad);

	void print();
	
	int getSelectedOption();

	String* getOptions();
};