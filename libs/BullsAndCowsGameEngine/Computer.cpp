#include <Computer.h>

Computer::Computer()
{
    randomSeed(analogRead(A3));
}

void Computer::generateNumber()
{
    int num = random(1000, 9999);
    
    while(this->hasDuplicates(num))
    {
        num = random(1000, 9999);
    }

    this->number = Number(num);
}

bool Computer::hasDuplicates(int num)
{
    bool digs[10];

    for(int i = 0;i < 10;i++)
    {
        digs[i] = false;
    }

    while(num > 0)
    {
        int digit = num % 10;

        if(digs[digit])
        {
            return true;
        }

        digs[digit] = true;
        num /= 10;
    }

    return false;
}