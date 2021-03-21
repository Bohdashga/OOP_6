#pragma once

#include <iostream>
#include <string>
#include "Stringable.h"

using namespace std;

class Date : public Stringable 
{
private:
    int day, month, year;
    int hours, minutes;
public:
    Date();
   
    Date(int day, int month, int year, int hours, int minutes);

    Date(const Date& date);

    int getDay()const;
    int getMonth()const;
    int getYear()const;
    int getHours()const;
    int getMinutes()const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setHours(int hours);

    void setMinutes(int minutes);

    string toString()const;

    void inputFromKeyboard();

    virtual string objectToString()const;
    virtual void stringToObject(string str);
};

