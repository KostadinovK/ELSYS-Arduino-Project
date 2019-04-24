#include <Menu.h>

Menu::Menu(String* options, int optionsCount, LiquidCrystal& screen, Keypad& keyPad)
{
	optionIndex = 0;
	this->options = options;
	this->optionsCount = optionsCount;
	
	this->screen = &screen;
	this->keyPad = &keyPad;

	this->screen->begin(16, 2);
}

void Menu::print()
{
	screen->print("Welcome User!");
	delay(1000);
	screen->clear();
	screen->print("Menu: ");
	screen->setCursor(0, 1);
	screen->print("2/8-up/down *-select");
	delay(500);

	for (int i = 0; i < 5; i++) {
		screen->scrollDisplayLeft();
		delay(500);
	}

	delay(500);
	screen->clear();
	screen->print("Menu:");
	screen->setCursor(0, 1);

	run();
}

void Menu::run() {

	char key = '1';

	while (key && key != Menu::SELECT_KEY) {

		if (key == Menu::UP_KEY) {
			optionIndex--;
		}
		else if (key == Menu::DOWN_KEY) {
			optionIndex++;
		}

		if (optionIndex >= optionsCount) {
			optionIndex = 0;
		}
		else if (optionIndex < 0)
		{
			optionIndex = optionsCount - 1;
		}

		screen->clear();
		screen->print("Menu:");
		screen->setCursor(0, 1);
		screen->print(options[optionIndex]);

		key = keyPad->getKey();
		while (!key) {
			key = keyPad->getKey();
		}
	}
	screen->clear();
}

int Menu::getSelectedOption()
{
	return this->optionIndex + 1;
}

String* Menu::getOptions()
{
	return this->options;
}