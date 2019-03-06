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
    screen->print("Surrender - 112");
    delay(2000);
    screen->clear();
}

void BullsAndCowsGameEngine::startGameLoop()
{
    while(!gameOver)
    {
        computer.generateNumber();
        player.makeGuess();

        if(player.guess.value == SURRENDER_CODE)
        {
            screen->print("You lose!");
            screen->setCursor(0, 1);
            screen->print("The number was");
            screen->print(computer.number.value);
            gameOver = true;
            break;
        }

        if(player.guess.value == computer.guess.value)
        {
            screen->print("You Won!");
            screen->setCursor(0, 1);
            screen->print("Your score: ");
            delay(1000);
            screen->print(player.score);
            gameOver = true;
            break;
        }

        checkForBullsAndCows(player.number);

        screen->clear();
        screen->print("B: " + player.number.bulls + " C: " + player.number.cows);
        screen->setCursor(0, 1);
        screen->print("*-continue #-log");

        triesLog += "N:" + player.number.value + " B:" + player.number.bulls + " C:" + player.number.cows + '\n';

        char key = keyPad->getKey();
		while (!key) {
			key = keyPad->getKey();
		}

        if(key == '#')
        {
            printLog();
        }

        tries++;
        player.score -= 10;
    }
}

void BullsAndCowsGameEngine::checkForBullsAndCows(Number& number)
{

}

void BullsAndCowsGameEngine::printLog()
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