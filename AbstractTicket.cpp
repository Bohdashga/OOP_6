#include "AbstractTicket.h"

int AbstractTicket::ID = 0;

AbstractTicket::AbstractTicket()
{
    number = ++ID * 100 + rand() % 100;
}

AbstractTicket::AbstractTicket(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber)
{
    number = ++ID * 100 + rand() % 100;
}

AbstractTicket::AbstractTicket(const AbstractTicket& obj)
{
    ID++;
    number = obj.number;
    arriveDate = new Date(*obj.arriveDate);
    departDate = new Date(*obj.departDate);
    departStation = obj.departStation;
    arriveStation = obj.arriveStation;
    raceNumber = obj.raceNumber;
}

AbstractTicket::~AbstractTicket()
{
    if (arriveDate != NULL)
        delete arriveDate;
    if (departDate != NULL)
        delete departDate;

    ID--;
}

int AbstractTicket::getCount()const { return ID; }

int AbstractTicket::getNumber() const { return number; }
Date AbstractTicket::getArriveDate()const { return *arriveDate; }
Date AbstractTicket::getDepartDate()const { return *departDate; }
string AbstractTicket::getDepartStation()const { return departStation; }
string AbstractTicket::getArriveStatiob()const { return arriveStation; }
int AbstractTicket::getRaceNumber()const { return raceNumber; }

void AbstractTicket::setDepartStation(string departStation) { this->departStation = departStation; }
void AbstractTicket::setArriveStation(string arriveStation) { this->arriveStation = arriveStation; }
void AbstractTicket::setRaceNumber(int raceNumber) { this->raceNumber = raceNumber; }

string AbstractTicket::objectToString()const
{
    string res = to_string(number) + ";" + departStation + ";" + departDate->objectToString() +
        ";" + arriveStation + ";" + arriveDate->objectToString() + ";" + to_string(raceNumber);
    return res;
}

void AbstractTicket::stringToObject(string str)
{

    vector<string> tokens;
    string delim = ";";
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    if (tokens.size() == 14) {
        number = stoi(tokens[0]);
        departStation = tokens[1];
        departDate->setDay(stoi(tokens[2]));
        departDate->setMonth(stoi(tokens[3]));
        departDate->setYear(stoi(tokens[4]));
        departDate->setHours(stoi(tokens[5]));
        departDate->setMinutes(stoi(tokens[6]));

        arriveStation = tokens[7];
        arriveDate->setDay(stoi(tokens[8]));
        arriveDate->setMonth(stoi(tokens[9]));
        arriveDate->setYear(stoi(tokens[10]));
        arriveDate->setHours(stoi(tokens[11]));
        arriveDate->setMinutes(stoi(tokens[12]));

    }
}

string AbstractTicket::toString()const
{
    string res = "Number: " + to_string(number) +
        "\nDepart station: " + departStation +
        "\nDepart date: " + departDate->toString() +
        "\nArrive station: " + arriveStation +
        "\nArrive date: " + arriveDate->toString() +
        "\nRace number: " + to_string(raceNumber) + "\n";
    return res;
}

void AbstractTicket::writeInFile(string fileName)
{
    ofstream file(fileName);

    if (file.is_open())
    {
        file << toString();
        file.close();
    }
}

void AbstractTicket::inputFromKeyboard()
{
    cout << "Depart station > ";
    cin >> departStation;

    cout << "Depart date:\n";
    departDate->inputFromKeyboard();

    cout << "Arrive station > ";
    cin >> arriveStation;

    cout << "Arrive date:\n";
    arriveDate->inputFromKeyboard();

    cout << "Race number:";
    cin >> raceNumber;

    sold = true;
}

int AbstractTicket::getCurrentID() const
{
    return number;
}

int AbstractTicket::getTotalCountOfObject()const
{
    return ID;
}


ifstream& operator>>(ifstream& out, AbstractTicket& ticket)
{
    string str;
    out >> str;
    ticket.stringToObject(str);

    return out;
}

ofstream& operator<<(ofstream& in, AbstractTicket& ticket) 
{
    in << ticket.objectToString() << endl;
    return in;
}