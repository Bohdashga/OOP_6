#pragma once

#include "AbstractTicket.h"

class Ticket : public AbstractTicket
{
private:
	
public:
    Ticket();

    Ticket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    Ticket(const Ticket& obj);

    ~Ticket();

    virtual bool sell();

    virtual bool sell(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    virtual bool sell(string departStation, string arriveStation, int raceNumber);

    virtual void cancelTicket();
};

