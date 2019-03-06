#pragma once

#include <Number.h>
#include <stdlib.h>
#include <time.h> 

class Computer
{
    private:
        Number number;

    public:
        Computer();

        void generateNumber();
        bool hasDuplicates();
        
        Number getNumber();
};