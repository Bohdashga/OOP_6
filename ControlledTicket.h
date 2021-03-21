#pragma once

#include "Ticket.h"

class ControlledTicket : public Ticket
{
protected:
	bool control;
public:
    ControlledTicket();

    ControlledTicket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    ControlledTicket(const ControlledTicket& obj);

    ~ControlledTicket();
	
    void cancelTicket();

    bool isControlled();
    void setControlled(bool control);

    virtual string toString();
};

