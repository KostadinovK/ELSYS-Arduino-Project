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

void BullsAndCowsGameEngine::startGame()
{
    drawIntro();
    startGameLoop();
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
    delay(1000);
    screen->clear();
}

void BullsAndCowsGameEngine::startGameLoop()
{
    computer.generateNumber();
    while(!gameOver)
    {
        screen->print("Enter your guess:");
        screen->setCursor(0,1);
        delay(200);

        int guess = this->makeGuess();

        player.makeGuess(guess);
        
        if(player.guess.getValue() == computer.number.getValue())
        {
            screen->clear();
            screen->print("You Won!");
            screen->setCursor(0, 1);
            screen->print("Your score: ");
            screen->print(player.score);
            gameOver = true;
            
            askForRestart(gameOver);

            if (gameOver) {
                return;
            }
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
        triesLog += guessString + " " + "B:" + bullsString + "  C:" + cowsString;

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
    const char SELECT_KEY = '*';
    const char UP_KEY = '2';
    const char DOWN_KEY = '8';

    int stringsLength = (triesLog.length() / 12);
    String strings[stringsLength];

    int startIndex = 0;
    int endIndex = 13;
    for(int i = 0; i < stringsLength; i++)
    {
        strings[i] = triesLog.substring(startIndex, endIndex);
        startIndex = endIndex;
        endIndex += 13;
    }

    char key = '1';
    int stringIndex = 0;

	while (key && key != SELECT_KEY) {

		if (key == UP_KEY) {
			stringIndex--;
		}
		else if (key == DOWN_KEY) {
			stringIndex++;
		}

		if (stringIndex >= stringsLength) {
			stringIndex = 0;
		}
		else if (stringIndex < 0)
		{
			stringIndex = stringsLength - 1;
		}

		screen->clear();
		screen->print("Log:");
		screen->setCursor(0, 1);
		screen->print(strings[stringIndex]);

		key = keyPad->getKey();
		while (!key) {
			key = keyPad->getKey();
		}
	}
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

void BullsAndCowsGameEngine::askForRestart(bool& gameOver)
{
    screen->clear();
    screen->print("Play Again?");
    screen->setCursor(0,1);
    screen->print("* - yes # - no");

    char key = keyPad->getKey();
	while (!key) {
	    key = keyPad->getKey();
	}

    if (key == '*') {
        gameOver = false;
        tries = 0;
        player.score = 200;
    }
}

int BullsAndCowsGameEngine::getTries()
{
    return this->tries;
}

bool BullsAndCowsGameEngine::getGameState()
{
    return this->gameOver;
}