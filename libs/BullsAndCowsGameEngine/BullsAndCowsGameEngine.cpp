#include <BullsAndCowsGameEngine.h>

BullsAndCowsGameEngine::BullsAndCowsGameEngine(Keypad& keyPad)
{
    this->keyPad = keyPad;
    this->player = Player();
    this->computer = Computer();
    this->gameOver = false;
    this->tries = 0;
    this->triesLog = String();
}

void BullsAndCowsGameEngine::printIntro()
{

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