#include <BullsAndCowsGameEngine.h>

BullsAndCowsGameEngine::BullsAndCowsGameEngine(Keypad keyPad, LiquidCrystal screen) : player(Player(keyPad)), computer(Computer())
{
    this->keyPad = &keyPad;
    this->screen = &screen;

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
    computer.generateNumber();
    while(!gameOver)
    {
        screen->print("Game loop...");
        delay(2000);
        screen->clear();

        screen->print("Enter your guess:");
        screen->setCursor(0,1);
        delay(2000);
        player.makeGuess();

        if(player.guess.getValue() == SURRENDER_CODE)
        {
            screen->print("You lose!");
            screen->setCursor(0, 1);
            screen->print("The number was");
            screen->print(computer.getNumber().getValue());
            gameOver = true;
            break;
        }

        if(player.guess.getValue() == SURRENDER_CODE)//player.guess.getValue() == computer.getNumber().getValue())
        {
            screen->print("You Won!");
            screen->setCursor(0, 1);
            screen->print("Your score: ");
            delay(1000);
            screen->print(player.score);
            gameOver = true;
            break;
        }

        checkForBullsAndCows(player.guess);

        screen->clear();
        screen->print("Debug..");
        delay(2000);
        //screen->print("B: " + /*convertToString(player.guess.getBulls()) + */" C: "/* + convertToString(player.guess.getCows())*/);
        screen->clear();
        screen->setCursor(0, 1);

        screen->print("*-continue #-log");

        screen->clear();
        screen->print("Debug2..");
        delay(2000);

        //triesLog += "N:" + /*convertToString(player.guess.getValue()) + */" B:" + /* convertToString(player.guess.getBulls()) +*/ " C:" + /*convertToString(player.guess.getCows()) + */'\n';

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

String BullsAndCowsGameEngine::convertToString(int num)
{
    String res = String(num);
    return res;
}

int BullsAndCowsGameEngine::getTries()
{
    return this->tries;
}

bool BullsAndCowsGameEngine::getGameState()
{
    return this->gameOver;
}