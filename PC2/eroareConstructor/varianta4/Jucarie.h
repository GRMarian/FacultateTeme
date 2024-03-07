#pragma once
#include<string>
using std::string;
class Jucarie
{
protected:
	string nume;
	double dbl;
public:
	Jucarie(string nume = "", double dbl = 0.0)
		:nume(nume), dbl(dbl){}
	~Jucarie();
	void Afisare();
};

