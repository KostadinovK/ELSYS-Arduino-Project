#include <BullsAndCowsGameEngine.h>

BullsAndCowsGameEngine::BullsAndCowsGameEngine(Keypad keyPad, LiquidCrystal screen)
{
    this->keyPad = &keyPad;
    this->screen = &screen;

    this->player = Player();
    this->computer = Computer();
    this->gameOver = false;
    this->tries = 0;
    this->triesLog = String();

    this->screen->clear();
}

void BullsAndCowsGameEngine::drawIntro()
{
    screen->print("Bulls And Cows");
    screen->setCursor(0, 1);
    screen->print("For Arduino");
    delay(1000);
    screen->clear();
    screen->print("4-digit number without dups");
    delay(500);

    for (int i = 0; i < 12; i++) {
		screen->scrollDisplayLeft();
		delay(300);
	}

    for (int i = 0; i < 14; i++) {
        screen->scrollDisplayRight();
    }

    screen->setCursor(0, 1);
    screen->print("starting 0 allowed");

    for (int i = 0; i < 8; i++) {
		screen->scrollDisplayLeft();
		delay(300);
	}

    delay(1000);

    screen->clear();
    screen->print("*-submit #-log");
    screen->setCursor(0, 1);
    screen->print("Starting...");
    delay(2000);
    screen->clear();
}

void BullsAndCowsGameEngine::startGameLoop()
{

}

int BullsAndCowsGameEngine::getTries()
{
    return this->tries;
}

bool BullsAndCowsGameEngine::getGameState()
{
    return this->gameOver;
}