#pragma once

#include <Number.h>
#include <stdlib.h>
#include <time.h> 

class Computer
{
    public:
        Number number;
        Computer();

        void generateNumber();
        bool hasDuplicates();
};