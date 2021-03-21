#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Numerable.h"
#include "Stringable.h"
#include <vector>

using namespace std;

class AbstractTicket : public Numerable, public Stringable
{
private:
    int static ID;
protected:
    int number;

    Date* arriveDate;
    Date* departDate;
    string departStation;
    string arriveStation;
    int raceNumber;

    bool sold;
public:
    string passanger;

    AbstractTicket();

    AbstractTicket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    AbstractTicket(const AbstractTicket& obj);

    ~AbstractTicket();

    int getCount()const;

    virtual bool sell() = 0;

    virtual bool sell(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber) = 0;

    virtual bool sell(string departStation, string arriveStation, int raceNumber) = 0;

    virtual void cancelTicket() = 0;

    int getNumber()const;
    Date getArriveDate()const;
    Date getDepartDate()const;
    string getDepartStation()const;
    string getArriveStatiob()const;
    int getRaceNumber()const;

    void setDepartStation(string departStation);
    void setArriveStation(string arriveStation);
    void setRaceNumber(int raceNumber);

    virtual string objectToString()const;
    virtual void stringToObject(string str);

    virtual string toString()const;

    void writeInFile(string fileName);

    void inputFromKeyboard();

    virtual int getCurrentID()const;
    virtual int getTotalCountOfObject()const;

    friend ifstream& operator>>(ifstream& out, AbstractTicket& ticket);
    friend ofstream& operator<<(ofstream& in, AbstractTicket& ticket);
};

