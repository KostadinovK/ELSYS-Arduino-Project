#include <Computer.h>

Computer::Computer()
{
    srand(time(NULL));
    this->number = Number();
}

void Computer::generateNumber()
{
    int num = rand() % 9999 + 1000;
    
    this->number = Number(num);

    while(this->hasDuplicates())
    {
        num = rand() % 9999 + 1000;
        this->number = Number(num);
    }
}

bool Computer::hasDuplicates()
{
    int value = this->number.getValue();
    bool digs[10];

    for(int i = 0;i < 10;i++)
    {
        digs[i] = false;
    }

    while(value > 0)
    {
        int digit = value % 10;

        if(digs[digit])
        {
            return true;
        }

        digs[digit] = true;
        value /= 10;
    }

    return false;
}

Number Computer::getNumber()
{
    return this->number;
}