#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Date.h"
#include "Ticket.h"
#include "ControlledTicket.h"

using namespace std;

void printTicketsList(AbstractTicket** tickets, int size)
{
    cout << "Tickets:\n\n";

    for (int i = 0; i < size; i++)
    {
        cout << tickets[i]->toString() << endl;
    }
}

void ticketFilling(AbstractTicket** tickets, int size)
{
    cout << "Filling tickers:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nSelect type:\n";
        cout << "1. Ticket\n";
        cout << "2. Controlled ticket\n";
        int menu;
        cin >> menu;

        if (menu == 1)
        {
            Ticket* ticket = new Ticket();
            ticket->inputFromKeyboard();
            tickets[i] = ticket;
        }
        else
        {
            ControlledTicket* ticket = new ControlledTicket();
            ticket->inputFromKeyboard();

            bool b;
            cout << "Is controlled (1-yes 0-no) > ";
            cin >> b;

            ticket->setControlled(b);
            tickets[i] = ticket;
        }
    }
}

void sortByID(Numerable** obj, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (obj[i]->getCurrentID() > obj[j]->getCurrentID())
            {
                Numerable* buffer = obj[i];
                obj[i] = obj[j];
                obj[j] = buffer;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    int size;

    cout << "Size > ";
    cin >> size;

    AbstractTicket** tickets = new AbstractTicket*[size];

    ticketFilling(tickets, size);

    cout << endl << endl;
    printTicketsList(tickets, size);

    string fileName;

    cout << "File name > ";
    cin >> fileName;

    ofstream fileW(fileName);


    cout << "Writing in file!\n\n";
    for (int i = 0; i < size; i++)
    {
        fileW << *(tickets[i]) << endl;
    }

    fileW.close();

    ifstream fileR(fileName);

    cout << "Reading from file!\n";
    for (int i = 0; i < size; i++)
    {
        fileR >> *(tickets[i]);
    }

    fileR.close();

    cout << "\n\nInfo from file!:\n";
    printTicketsList(tickets, size);

    Numerable** ptr = (Numerable**)tickets;
    sortByID(ptr, size);

    cout << "\n\nSorted file!:\n";
    printTicketsList(tickets, size);

    return 0;
}
