#pragma once

#include <Arduino.h>
#include <Number.h> 

class Computer
{
    public:
        Number number;
        Computer();

        void generateNumber();
        
    private:
        bool hasDuplicates(int num);
};