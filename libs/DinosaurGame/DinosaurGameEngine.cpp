#include <DinosaurGameEngine.h>

DinosaurGameEngine::DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen) : GameEngine(keyPad, screen)
{

}

void DinosaurGameEngine::startGame()
{
    screen->clear();
    screen->print("Dinosaur");
}
