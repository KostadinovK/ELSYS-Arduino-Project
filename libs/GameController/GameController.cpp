#include <GameController.h>

GameController::GameController(Keypad& keyPad, LiquidCrystal& screen, MenuItem* options, int option)
{
    this->keyPad = &keyPad;
    this->screen = &screen;
    this->selectedOption = option;
    this->options = options;

    this->screen->clear();
}

void GameController::executeSelectedOption()
{
    options[selectedOption].gameEngine->startGame();
}
