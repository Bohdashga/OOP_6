#include "Ticket.h"

Ticket::Ticket() : AbstractTicket()
{
    cancelTicket();
}

Ticket::Ticket(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber) : AbstractTicket()
{
    sell(departDate, arriveDate, departStation, arriveStation, raceNumber);
}

Ticket::Ticket(const Ticket& obj) : AbstractTicket(obj)
{
}

Ticket::~Ticket()
{
}

bool Ticket::sell()
{
    return sold;
}

bool Ticket::sell(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber)
{
    if (!sold)
    {
        this->departDate = new Date(departDate);
        this->arriveDate = new Date(arriveDate);
        this->departStation = departStation;
        this->arriveStation = arriveStation;
        this->raceNumber = raceNumber;

        sold = true;
    }
    return sold;
}


bool Ticket::sell(string departStation, string arriveStation, int raceNumber)
{
    if (!sold)
    {
        this->departStation = departStation;
        this->arriveStation = arriveStation;
        this->raceNumber = raceNumber;

        sold = true;
    }
    return sold;
}

void Ticket::cancelTicket()
{
    if (arriveDate != NULL)
        delete arriveDate;
    if (departDate != NULL)
        delete departDate;

    arriveDate = new Date();
    departDate = new Date();
    departStation = "";
    arriveStation = "";
    raceNumber = 0;
    passanger = "";

    sold = false;
}
