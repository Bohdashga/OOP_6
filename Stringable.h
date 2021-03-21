#pragma once
#include <string>

using namespace std;

class Stringable
{
public:
	virtual string objectToString()const = 0;
	virtual void stringToObject(string str) = 0;
};

