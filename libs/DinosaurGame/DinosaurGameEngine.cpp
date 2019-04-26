#include <DinosaurGameEngine.h>

DinosaurGameEngine::DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen) : GameEngine(keyPad, screen)
{

}

void DinosaurGameEngine::startGame()
{

    byte dino[8] = {
        0b00000,
        0b00111,
        0b00111,
        0b10110,
        0b11111,
        0b01010,
        0b01010,
        0b00000
    };

    byte cactus[8] = {
        0b00100,
        0b00101,
        0b10101,
        0b10101,
        0b10111,
        0b11100,
        0b00100,
        0b00000
    };

    byte bird[8] = {
        0b00000,
        0b00100,
        0b01100,
        0b11110,
        0b00111,
        0b00110,
        0b00100,
        0b00000
    };

    byte block[8] = {
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };

    int adc_key_in  = 0;

    byte runnerArea[16] {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
    byte jump = 32;

    int score = 0;
    bool stopScoring = false;

    byte correct_code = 123;

    unsigned long previousMillis = 0;
    unsigned long jumpTime = 0;
    const int jumpLength = 500;
    const byte chance_of_ob = 15;
    int objectChance = 0;
    int speedOfScroller = 300;

    screen->createChar(0, dino);
    screen->createChar(1, cactus);
    screen->createChar(2, bird);
    screen->createChar(3, block);
  
    randomSeed(6);
    screen->clear();
    showHomeScreen();

    while(true)
    {
        unsigned long currentMillis = millis();
        unsigned long currentMillisOb = millis();

        if (currentMillisOb - previousMillis >= speedOfScroller) 
        {
            previousMillis = currentMillisOb;
            objectChance = random(0,3);
            if (objectChance == 0)
            {
                runnerArea[15] = 1;
            }
            else if (objectChance == 1)
            {
                runnerArea[15] = 2;
            }
            else
            {
                runnerArea[15] = 32;
            }
            delay(500);
            for (int i = 0; i < 15; i++)
            {
                 runnerArea[i] = runnerArea[i + 1];
            }

            if (!stopScoring)
            {
                score++;
            }
        }
        runnerArea[0] = 3;
        runnerArea[15] = 3;

        if (readKey() == DinosaurGameEngine::SELECT_KEY)
        {
            if (runnerArea[1] != 32 && (runnerArea[1] != 1 || runnerArea[1] != 2))
            {
                runnerArea[1] = 32;
            }

            jump = 0;
            stopScoring = true;
            jumpTime = millis();
        }

        if (millis() - jumpTime >= jumpLength)
        {
            if (runnerArea[1] == 32 || runnerArea[1] == 0)
            {
                runnerArea[1] = 0;
                jump = 32;
                stopScoring = false;
            }
            else
            {
                showCrashScreen();
                break;
            }
        }

        for (int i = 0; i < 16; i++)
        {
            screen->setCursor(i, 1);
            screen->write(runnerArea[i]);
        }

        screen->setCursor(1, 0);
        screen->write(jump);

        screen->setCursor(4, 0);
        screen->print("Score: ");
        screen->setCursor(11, 0);
        screen->print(score);
    }
}

void DinosaurGameEngine::showHomeScreen()
{

    screen->clear();
    screen->print("Press * to play");
    drawHomeGraphics();
    delay(1000);
    screen->clear();
}

void DinosaurGameEngine::drawHomeGraphics()
{

  screen->setCursor(0, 1);
  screen->write(byte(3));
  screen->setCursor(15, 1);
  screen->write(byte(3));
  screen->setCursor(1, 1);
  screen->write(byte(0));
}

void DinosaurGameEngine::drawBarrier()
{

}

char DinosaurGameEngine::readKey() 
{
    char key = keyPad->getKey();

    while (!key) {
		key = keyPad->getKey();
	}

    return key;
}

void DinosaurGameEngine::showCrashScreen()
{
    screen->setCursor(4, 1);
    screen->print("Game Over!");
    delay(2000);
}

void DinosaurGameEngine::updateLcd()
{
}

void DinosaurGameEngine::printScore()
{
  
}