#pragma once

#include <Number.h>

class Computer
{
    private:
        Number number;

    public:
        Computer();

        void generateNumber();
        bool hasDupes();
        
        int getNumber();
};