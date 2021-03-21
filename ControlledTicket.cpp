#include "ControlledTicket.h"

ControlledTicket::ControlledTicket() : Ticket()
{
    cancelTicket();
}

ControlledTicket::ControlledTicket(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber) : Ticket(departDate,arriveDate,departStation,arriveStation,raceNumber)
{
    
}

ControlledTicket::ControlledTicket(const ControlledTicket& obj) : Ticket(obj)
{
}

ControlledTicket::~ControlledTicket()
{
}

void ControlledTicket::cancelTicket() 
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

    control = false;
}

bool ControlledTicket::isControlled()
{
    return control;
}

void ControlledTicket::setControlled(bool control)
{
    this->control = control;
}

string ControlledTicket::toString()
{
    string res = "Number: " + to_string(number) +
        "\nDepart station: " + departStation +
        "\nDepart date: " + departDate->toString() +
        "\nArrive station: " + arriveStation +
        "\nArrive date: " + arriveDate->toString() +
        "\nRace number: " + to_string(raceNumber) +
        "\nIs controlled: " + (control?"Yes":"No") + "\n";
    return res;
}