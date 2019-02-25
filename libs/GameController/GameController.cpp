#include <GameController.h>

GameController::GameController(String* options, int option)
{
    this->selectedOption = option;
    this->options = options;
}

void GameController::executeSelectedOption()
{
    if(selectedOption == 0 && options[selectedOption] == "1.Bulls and Cows")
    {
        BullsAndCowsGameEngine engine();
        engine.drawIntro();
        engine.startGameLoop();

    }else if(selectedOption == 1 && options[selectedOption] == "2.Dinosaur Game")
    {

    }
}