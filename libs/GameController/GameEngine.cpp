#include <GameEngine.h>


GameEngine::GameEngine(Keypad& keyPad, LiquidCrystal& screen)
{
    this->keyPad = &keyPad;
    this->screen = &screen;
}