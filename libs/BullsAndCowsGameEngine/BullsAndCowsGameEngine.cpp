#include <BullsAndCowsGameEngine.h>

BullsAndCowsGameEngine::BullsAndCowsGameEngine(Keypad& keyPad, LiquidCrystal& screen) : player(Player(keyPad)), computer(Computer())
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
        screen->print("Enter your guess:");
        screen->setCursor(0,1);
        delay(2000);

        int guess = this->makeGuess();

        player.makeGuess(guess);

        if(player.guess.getValue() == SURRENDER_CODE)
        {
            screen->print("You lose!");
            screen->setCursor(0, 1);
            screen->print("The number was");
            screen->print(computer.number.getValue());
            gameOver = true;
            break;
        }
        
        if(player.guess.getValue() == computer.number.getValue())
        {
            screen->print("You Won!");
            screen->setCursor(0, 1);
            screen->print("Your score: ");
            delay(1000);
            screen->print(player.score);
            gameOver = true;
            break;
        }

        screen->clear();

        int bulls = player.guess.getBulls();
       
        screen->print("B:");
        screen->print(bulls);
        screen->print("  C:");
        int cows = player.guess.getCows();
        screen->print(cows);
       
        screen->setCursor(0, 1);
        screen->print("*-continue #-log");

        String guessString = String(guess);
        String bullsString = String(bulls);
        String cowsString = String(cows);
        triesLog += guessString + " " + "B: " + bullsString + "  C: " + cowsString;

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
        screen->clear();
        delay(1000);
    }
}

void BullsAndCowsGameEngine::checkForBullsAndCows(Number& number)
{

}

void BullsAndCowsGameEngine::printLog()
{
    
}
int BullsAndCowsGameEngine::makeGuess(){
    int arr[4];
    
    while(true){
        for(int i = 0; i < 4; i++)
        {
            char key = keyPad->getKey();
	        while (!key) {
	            key = keyPad->getKey();
	        }
            arr[i] = key - '0';
            screen->setCursor(i, 1);
            screen->print(arr[i]);
        }
        delay(1000);
        if(!hasDuplicates(arr))
        {
            break;
        }
        
        screen->clear();
        screen->print("Invalid guess!");
        delay(1000);
        screen->clear();
        screen->print("Enter your guess:");
    }

    int value = 0;
    value += arr[0] * 1000;
    value += arr[1] * 100;
    value += arr[2] * 10;
    value += arr[3];

    return value;
}
bool BullsAndCowsGameEngine::hasDuplicates(int value[]){
    bool digs[10];

    for(int i = 0;i < 10;i++)
    {
        digs[i] = false;
    }

    for(int i = 0; i < 4; i++)
    {
        if(digs[value[i]])
        {
            return true;
        }
         digs[value[i]] = true;
    }
    

    return false;
}
int BullsAndCowsGameEngine::getTries()
{
    return this->tries;
}

bool BullsAndCowsGameEngine::getGameState()
{
    return this->gameOver;
}