#include <GameController.h>

GameController::GameController(Keypad keyPad, LiquidCrystal screen, String* options, int option)
{
    this->keyPad = &keyPad;
    this->screen = &screen;
    this->selectedOption = option;
    this->options = options;

    this->screen->clear();
}

void GameController::executeSelectedOption()
{
    if(selectedOption == 1 && options[selectedOption - 1] == "1.Bulls and Cows")
    {
        BullsAndCowsGameEngine engine = BullsAndCowsGameEngine(*this->keyPad, *this->screen);
        engine.drawIntro();
        engine.startGameLoop();

    }else if(selectedOption == 2 && options[selectedOption - 1] == "2.Dinosaur Game")
    {

    }
}
