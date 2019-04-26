#include <DinosaurGameEngine.h>

DinosaurGameEngine::DinosaurGameEngine(Keypad& keyPad, LiquidCrystal& screen) : GameEngine(keyPad, screen)
{ 
    jump = 32;
    score = 0;
    stopScoring = false;
    jumpTime = 0;
}

void DinosaurGameEngine::startGame()
{
    intro();
    gameLoop();
}

void DinosaurGameEngine::intro()
{
    byte dinosaur[8] = {
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

    screen->createChar(0, dinosaur);
    screen->createChar(1, cactus);
    screen->createChar(2, bird);
    screen->createChar(3, block);

    for(int i = 0; i < 16; i++)
    {
        field[i] = 32;
    }

    randomSeed(6);
    screen->clear();
    showHomeScreen();
}

void DinosaurGameEngine::gameLoop()
{
    while(true)
    {
        objectChance = random(0,3);
        if (objectChance == 0)
        {
            field[15] = 1;
        }
        else if (objectChance == 1)
        {
            field[15] = 2;
        }
        else
        {
            field[15] = 32;
        }
        delay(500);
        for (int i = 0; i < 15; i++)
        {
            field[i] = field[i + 1];
        }

        if (!stopScoring)
        {
            score++;
        }
    
        field[0] = 3;
        field[15] = 3;

        if (readKey() == DinosaurGameEngine::SELECT_KEY)
        {
            if (field[1] != 32 && (field[1] != 1 || field[1] != 2))
            {
                field[1] = 32;
            }

            jump = 0;
            stopScoring = true;
            jumpTime = millis();
        }

        if (millis() - jumpTime >= jumpLength)
        {
            if (field[1] == 32 || field[1] == 0)
            {
                field[1] = 0;
                jump = 32;
                stopScoring = false;
            }
            else
            {
                screen->setCursor(4, 1);
                screen->print("Game Over!");
                delay(2000);
                return;
            }
        }

        for (int i = 0; i < 16; i++)
        {
            screen->setCursor(i, 1);
            screen->write(field[i]);
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
    screen->print("Dinosaur Game");
    screen->setCursor(0,1);
    screen->print("* - jump #-walk");
    delay(2000);
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

char DinosaurGameEngine::readKey() 
{
    char key = keyPad->getKey();

    while (!key) {
		key = keyPad->getKey();
	}

    return key;
}