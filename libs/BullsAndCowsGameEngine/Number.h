#pragma once

class Number
{
    private:
        int value;
        int bulls;
        int cows;
        bool isValid;

        int getNumberDigits(int num);
        bool hasDuplicates(int num);

    public:
        Number();
        Number(int num);
        
        bool checkIsValid(int num);

        void addCow();
        void addBull();

        int getValue();
        int getBulls();
        int getCows();
        bool getIsValid();
};