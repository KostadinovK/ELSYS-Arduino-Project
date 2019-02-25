#pragma once

class Number
{
    private:
        int value;
        int bulls;
        int cows;
        bool isValid;

    public:
        Number();
        Number(int num); //with exception throwing

        bool checkIsValid();

        void addCow();
        void addBull();

        int getValue();
        int getBulls();
        int getCows();
        bool getIsValid();
};