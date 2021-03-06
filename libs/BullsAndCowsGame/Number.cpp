#include <Number.h>

Number::Number()
{
    value = 0;
    bulls = 0;
    cows = 0;
    isValid = false;
}

Number::Number(int num)
{
    value = num;
    bulls = 0;
    cows = 0;
    isValid = true;
}

int Number::getNumberDigits(int num)
{
    int digits = 0;
    int n = num;
    while(n > 0)
    {
        n = n / 10;
        digits++;
    }

    return digits;
}

bool Number::hasDuplicates(int num)
{
    int n = num;
    bool digs[10];

    for(int i = 0; i < 10; i++)
    {
        digs[i] = false;
    }
    
    while(n > 0){
        int digit = n % 10;

        if(digs[digit])
        {
            return false;
        }
        digs[digit] = true;
        n /= 10;
    }

    return true;   
}

bool Number::checkIsValid(int num)
{
    int digits = getNumberDigits(num);

    if(digits != 4)
    {
        return false;
    }

    if(hasDuplicates(num))
    {
        return false;
    }

    return true;
}

void Number::addBull()
{
    this->bulls++;
}

void Number::addCow()
{
    this->cows++;
}

void Number::addBull(int bulls)
{
    this->bulls += bulls;
}

void Number::addCow(int cows)
{
    this->cows += cows;
}


void Number::updateValue(int value){
    this->value = value;
    this->bulls = 0;
    this->cows = 0;
}

int Number::getValue()
{
    return this->value;
}

int Number::getBulls()
{
    return this->bulls;
}

int Number::getCows()
{
    return this->cows;
}

bool Number::getIsValid()
{
    return this->isValid;
}

